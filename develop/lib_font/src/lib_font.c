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
 *  Creation: 2018-08-09, @EmbeddedAl
 */


/* includes */
#include "lib_font.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "errno.h"
#include "lib_font__standard.h"




int putCharToBuffer(uint8_t *frameBuffer, uint16_t frameBufferWidth, uint16_t frameBufferHeight, uint16_t dstWidth, uint16_t dstHeight, char inChar)
{
	fontInfo_t fontInfo = lib_font__standard__getCharInfo(inChar);
	uint8_t srcBytesPerLine = (fontInfo.charWidth + 7) / 8;
	uint16_t deflatedSize = fontInfo.charWidth * fontInfo.charHeight;
	uint8_t *deflatedChar;
	uint8_t *dstFrameBuffer;
	uint16_t i;

	// param check for dstFrameBuffer buffer
	if (frameBuffer == NULL)
		return -EINVAL;

	// check destination numbers are within buffer boundaries
	if (dstWidth > frameBufferWidth || dstHeight > frameBufferHeight)
		return -EINVAL;

	// check if char fits to buffer; in width direction
	if (dstWidth + fontInfo.charWidth > frameBufferWidth)
		return -ENOSPC;

	// check if char fits to buffer; in height direction
	if (dstHeight + fontInfo.charHeight > frameBufferHeight)
		return -ENOSPC;

	// allocate space for deflating char
	deflatedChar = malloc(deflatedSize);
	if (deflatedChar == NULL)
		return -ENOMEM;

	// set destination framebuffer pointer
	dstFrameBuffer = &frameBuffer[dstHeight * frameBufferWidth + dstWidth];

	/* deflate char from original char buffer */
	for (i = 0; i < deflatedSize; i++)
	{
		// address the source's beginning
		uint16_t sourceIdx = 0;

		// address the source's line
		uint16_t line = i / fontInfo.charWidth;
		sourceIdx += line * srcBytesPerLine;
		uint16_t relativeBitPos = i - (line *fontInfo.charWidth);

		// address correct byte of line
		sourceIdx += relativeBitPos / 8;
		relativeBitPos = relativeBitPos % 8;

		// extract correct bit
		uint8_t bit = (fontInfo.charBuffer[sourceIdx] >> (8-relativeBitPos-1)) & 0x01;

		deflatedChar[i] = bit ? 1 : 0;
	}

	/* put deflated char to the output buffer */
	for (i = 0; i < deflatedSize; i++)
	{
		uint16_t LineNumber = i / fontInfo.charWidth;
		uint16_t dstLineOffset = LineNumber * frameBufferWidth;
		uint16_t dstByteOffset = i % fontInfo.charWidth;
		dstFrameBuffer[dstLineOffset + dstByteOffset] = deflatedChar[i];
	}

	free(deflatedChar);
	return 0;
}
