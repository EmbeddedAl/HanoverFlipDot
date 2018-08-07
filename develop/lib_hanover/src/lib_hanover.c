/*
 *  This file is part of the HanoverFlipDot project
 *  (https://github.com/EmbeddedAl/HanoverFlipDot).
 *
 *  HanoverFlipDot is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  HanoverFlipDot is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HanoverFlipDot. If not, see <https://www.gnu.org/licenses/>.
 *
 *  Creation: 2018-08-07, @EmbeddedAl
 */

/*
 * Hanover display frame as it is sent on the communication bus:
 * -------------------------------------------------------------
 *
 * Byte index: [ 0 ] [ 1 ] [ 2 ] [ 3 ] [ 4 ] [5] [.........................]
 * Byte name:  [SOF] [INS] [ADD] [LEH] [LEL] [D] [...] [D] [EOF] [CKH] [CKL]
 *
 * 	           SOF: Start of frame
 * 	           INS: Instruction byte
 * 	           ADD: Address of destination device
 * 	           LEH: High length byte
 * 	           LEL: Low length byte
 * 	           D:   Several data bytes
 * 	           EOF: End of frame byte
 * 	           CKH: High checksum byte
 * 	           CKL: Low checksum byte
 */


/* includes */
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "lib_hanover.h"
#include "lib_support.h"


/* defines for frame start and frame end of the hanover display */
#define LIB_HANOVER__FRAME_START 				0x02
#define LIB_HANOVER__FRAME_END					0x03

/* defines for the instruction bytes */
#define LIB_HANOVER__INS_WRITE					0x31

/* defines for the lengths of header and trailer */
#define LIB_HANOVER__LEN_HEADER					5
#define LIB_HANOVER__LEN_TRAILER				3

/* defines for the offsets to the buffers */
#define LIB_HANOVER__TXBUFIDX_FRAME_START		0
#define LIB_HANOVER__TXBUFIDX_INS				1
#define LIB_HANOVER__TXBUFIDX_ADDRESS			2
#define LIB_HANOVER__TXBUFIDX_LEN_MSB			3
#define LIB_HANOVER__TXBUFIDX_LEN_LSB			4


/* the handle definition for this implementation */
struct lib_hanover_handle {
	lib_serial_hdl serial_hdl;		/* serial handle required for transmission */
	uint8_t address;				/* address of the destination display      */
	uint16_t width;				    /* width of display in pixels              */
	uint16_t height;				/* height of display in pixels             */
	uint32_t bytesPerColumn;		/* bytes per column used                   */
	uint32_t txDataLen;				/* length of payload data within a frame   */
	uint32_t txBufferLen;			/* transmission buffer length              */
	uint8_t *txBuffer;				/* transmission buffer for a full frame    */
};


/* Func: lib_hannover__create_checksum()
 * Desc: Create a checksum over the prepared data buffer
 * Param-in hdl: the handle to be used for checksum calculation
 * Return: On success 0 is returned
 */
static int lib_hannover__create_checksum(lib_hanover_hdl hdl)
{
	uint8_t chk_byte = 0;
	uint8_t chk_ascii_h;
	uint8_t chk_ascii_l;
	uint32_t idx;

	/* checksum adding all header and data bytes */
	for (idx = 0; idx < (LIB_HANOVER__LEN_HEADER + hdl->txDataLen); idx++)
		chk_byte += hdl->txBuffer[idx];

	//+1
	chk_byte += 1;

	chk_byte = (chk_byte ^ 255) + 1;

	/* convert the checksum to two ASCII bytes */
	chk_ascii_h = lib_support__nibble2ascii(LIB_SUPPORT__NIBBLE_HI(chk_byte));
	chk_ascii_l = lib_support__nibble2ascii(LIB_SUPPORT__NIBBLE_LO(chk_byte));

	/* inject ASCII bytes to the transmission buffer (index is already set to the end of frame) */
	hdl->txBuffer[idx+1] = chk_ascii_h;
	hdl->txBuffer[idx+2] = chk_ascii_l;

	return 0;
}




lib_hanover_hdl lib_hanover__create(lib_serial_hdl serial_hdl, uint8_t address, uint16_t width, uint16_t height)
{
	lib_hanover_hdl hdl;

	/* serial parameter check */
	if (serial_hdl == NULL)
		return NULL;

	/* create handle space */
	hdl = malloc(sizeof(struct lib_hanover_handle));
	if (hdl == NULL)
		return NULL;

	/* initialize the new data structure */
	hdl->serial_hdl = serial_hdl;
	hdl->address = address;
	hdl->width = width;
	hdl->height = height;

	/* there is one byte required for 4 dots in one column */
	hdl->bytesPerColumn = (height / 4);
	if (height % 4)
		hdl->bytesPerColumn++;

	/* the total length of payload to be transmitted to a display of this size */
	hdl->txDataLen = (hdl->bytesPerColumn) * width;

	/* the total length of a framed packet sent to a display of this size */
	hdl->txBufferLen = LIB_HANOVER__LEN_HEADER + hdl->txDataLen + LIB_HANOVER__LEN_TRAILER;
	hdl->txBuffer = malloc(hdl->txBufferLen);
	if (hdl->txBuffer == NULL)
	{
		free(hdl);
		return NULL;
	}

	/* initialize data buffer with constants */
	hdl->txBuffer[LIB_HANOVER__TXBUFIDX_FRAME_START] 			= LIB_HANOVER__FRAME_START;
	hdl->txBuffer[LIB_HANOVER__TXBUFIDX_ADDRESS] 				= lib_support__nibble2ascii(hdl->address + 1);
	hdl->txBuffer[LIB_HANOVER__TXBUFIDX_LEN_MSB]				= lib_support__nibble2ascii(LIB_SUPPORT__NIBBLE_HI(hdl->txDataLen/2));
	hdl->txBuffer[LIB_HANOVER__TXBUFIDX_LEN_LSB]				= lib_support__nibble2ascii(LIB_SUPPORT__NIBBLE_LO(hdl->txDataLen/2));
	hdl->txBuffer[LIB_HANOVER__LEN_HEADER + hdl->txDataLen] 	= LIB_HANOVER__FRAME_END;

	return hdl;
}

int lib_hanover__destroy(lib_hanover_hdl *hdl)
{
	/* hdl param check */
	if (*hdl == NULL)
		return -EINVAL;

	/* txBuffer within the handle */
	if ((*hdl)->txBuffer == NULL)
		return -EFAULT;

	/* free allocated space and declare handle as invalid */
	free((*hdl)->txBuffer);
	free(*hdl);
	*hdl = NULL;

	/* all good */
	return 0;
}



int lib_hanover__writeHanoverDataFormat(lib_hanover_hdl hdl, uint8_t *data, uint32_t len)
{
	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	/* len param check */
	if (len != hdl->txDataLen)
		return -ENOEXEC;

	/* set write instruction */
	hdl->txBuffer[LIB_HANOVER__TXBUFIDX_INS] = LIB_HANOVER__INS_WRITE;

	/* put in the raw data */
	memcpy(&hdl->txBuffer[LIB_HANOVER__LEN_HEADER], data, len);

	/* build checksum */
	if (lib_hannover__create_checksum(hdl) != 0)
		return -EFAULT;

	/* data transmission */
	if (lib_serial_write(hdl->serial_hdl, hdl->txBuffer, hdl->txBufferLen) != 0)
		return -EIO;

	return 0;
}
