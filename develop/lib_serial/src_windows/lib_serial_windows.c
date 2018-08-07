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


/* includes */
#include <lib_serial.h>
#include <windows.h>
#include <errno.h>


/* the handle definition for this implementation */
struct lib_serial_handle{
	HANDLE winserial_hdl;
};


lib_serial_hdl lib_serial_create(const char *port)
{
	lib_serial_hdl hdl = NULL;
	DWORD accessdirection = GENERIC_READ | GENERIC_WRITE;

	/* param check */
	if (port == NULL)
		return NULL;

	/* create handle space */
	hdl = malloc(sizeof(struct lib_serial_handle));
	if (hdl == NULL)
		return NULL;

	/* initialize the new data structure */
	hdl->winserial_hdl = NULL;

	/* create the windows handle */
	hdl->winserial_hdl = CreateFile(port,
		accessdirection,
		0,
		0,
		OPEN_EXISTING,
		0,
		0);

	/* check success */
	if (hdl->winserial_hdl == INVALID_HANDLE_VALUE)
	{
		free(hdl);
		return NULL;
	}

	return hdl;
}


int lib_serial_open(lib_serial_hdl hdl, uint32_t baudrate)
{
	DCB dcbSerialParams = {0};
	dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	/* get communcation state */
	if (!GetCommState(hdl->winserial_hdl, &dcbSerialParams))
		return -EIO;

	/* set communication state as requested */
	dcbSerialParams.BaudRate=baudrate;
	dcbSerialParams.ByteSize=8;
	dcbSerialParams.Parity=NOPARITY;
	dcbSerialParams.StopBits=ONESTOPBIT;
	if(!SetCommState(hdl->winserial_hdl, &dcbSerialParams))
		return -EIO;

	/* success */
	return 0;
}


int lib_serial_close(lib_serial_hdl hdl)
{
	// Todo: check if there is anything to do for the windows implementation
	return 0;
}


int lib_serial_destroy(lib_serial_hdl *hdl)
{
	/* hdl param check */
	if (*hdl == NULL)
		return -EINVAL;

	/* close the windows handle */
	CloseHandle((*hdl)->winserial_hdl);

	/* free allocated space and declare handle as invalid */
	free(*hdl);
	*hdl = NULL;

	/* all good */
	return 0;
}


int lib_serial_write(lib_serial_hdl hdl, uint8_t *data, int len)
{
	DWORD dwBytesRead = 0;
	COMMTIMEOUTS commTimeouts = {0};
	uint32_t idx;
	
	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	// TODO: this implementation is not multithreading safe

    /* set timeout settings for the port */
	commTimeouts.ReadIntervalTimeout = 50;
	commTimeouts.ReadTotalTimeoutConstant = 50;
	commTimeouts.ReadTotalTimeoutMultiplier = 10;
	commTimeouts.WriteTotalTimeoutConstant = 500;
	commTimeouts.WriteTotalTimeoutMultiplier = 100;
    if(SetCommTimeouts(hdl->winserial_hdl, &commTimeouts) == 0)
        return -EIO;

    // TODO: currently only a bytewise write is working properly, needs investigation
	for (idx = 0; idx < len; idx++)
	{
		WriteFile(hdl->winserial_hdl, &data[idx], 1, &dwBytesRead, NULL);
	}
	FlushFileBuffers(hdl->winserial_hdl);

	return 0;
}
