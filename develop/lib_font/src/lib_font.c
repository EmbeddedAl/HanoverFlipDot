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
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include "lib_font.h"
#include "lib_font__standard.h"

/* defines */
#define LIB_FONT__CONSECUTIVETEXT__TEXTLENMAX 		1024


/* the consecutiveText handle definition for this implementation */
struct lib_font_consecutiveText_handle {
	lib_font__framebuffer_t fB;
	uint8_t *textBuffer;
	uint16_t textLen;
	uint8_t optCenterHoizontal;
	uint8_t optCenterVertical;
	uint8_t optFrameTheText;
	uint16_t intProgressInfo;
};



/* Func: lib_font__getNumOfCharsFitIn()
 * Desc: Get Number of characters of '*text' that fit into a screen with the width of 'availDotsX' pixels.
 *       The first character of '*text' must be printable.
 * Param-in availDotsX: available (remaining) pixels on the screen
 * Param-in text: pointer to the text to be analyzed
 * Param-in maxLen: maximum length of the text
 * Param-out numChars: number of characters of '*text' that fit in
 * Return:	0 on success
 * 			-EINVAL: input invalid
 */
static int lib_font__getNumOfCharsFitIn(uint16_t availDotsX, uint8_t *text, uint16_t maxLen, uint16_t *numChars)
{
	uint8_t currentChar;
	fontInfo_t currentCharFontInfo;
	uint16_t i;

	/* text must not be NULL; length must not be 0 */
	if ((text == NULL) || (maxLen == 0))
		return -EINVAL;

	/* numChars must be provided as output */
	if (numChars == NULL)
		return -EINVAL;

	/* the first character must be printable */
	if (lib_font__standard__isCharPrintable(text[0]) == 0)
		return -EINVAL;

	/* initialize user's return variable */
	*numChars = 0;

	/* is there space at all? */
	if (availDotsX == 0)
		return 0;

	/* check char by char */
	for (i = 0; i < maxLen; i++)
	{
		/* extract information about this char from the font */
		currentChar = text[i];
		currentCharFontInfo = lib_font__standard__getCharInfo(currentChar);

		/* if it doesn't fit, return current number to caller */
		if(currentCharFontInfo.charWidth > availDotsX)
			break;

		/* now, less dots are available */
		availDotsX -= currentCharFontInfo.charWidth;

		/* for the next letter we will need a dot as a space between two chars */
		if (availDotsX > 0)
			availDotsX -= 1;
	}

	/* return current number to caller */
	*numChars = i;
	return 0;
}


/* Func: lib_font__calcRequiredPixels()
 * Desc: Calculates the number of required pixels needed for a text provided in '*text'
 * Param-in text: the input text to be analyzed
 * Param-in textLen: the length of the text
 * Return: number of pixels required
 */
static uint16_t lib_font__calcRequiredPixels(uint8_t *text, uint16_t textLen)
{
	uint16_t i;
	uint16_t requiredPixels = 0;

	for (i = 0; i < textLen; i++)
	{
		fontInfo_t fontInfo = lib_font__standard__getCharInfo(text[i]);
		requiredPixels += fontInfo.charWidth;

		/* space if not at the end */
		if (i + 1 != textLen)
			requiredPixels++;

	}

	return requiredPixels;
}

/* Func: lib_font__drawFrame()
 * Desc: Draw a frame on the framebuffer
 * Param-in fB: the framebuffer
 * Return: void
 */
static void lib_font__drawFrame(lib_font__framebuffer_t fB)
{
	uint16_t cntLine;
	uint16_t cntCol;

	/* line by line */
	for (cntLine = 0; cntLine < fB.frameBufferHeight; cntLine++)
	{
		/* column by column */
		for (cntCol = 0; cntCol < fB.frameBufferWidth; cntCol++)
		{
			/* for the first and last line, print all pixels */
			if (cntLine == 0 || cntLine == fB.frameBufferHeight-1)
				fB.frameBuffer[(cntLine * fB.frameBufferWidth) + cntCol] = 0x01;

			/* otherwise only print the first and last column */
			else if (cntCol == 0 || cntCol == fB.frameBufferWidth-1)
				fB.frameBuffer[(cntLine * fB.frameBufferWidth) + cntCol] = 0x01;
		}
	}
	return;
}


int lib_font__putCharToFrameBuffer(uint8_t *frameBuffer, uint16_t frameBufferWidth, uint16_t frameBufferHeight, uint16_t dstWidth, uint16_t dstHeight, char inChar)
{
	fontInfo_t fontInfo = lib_font__standard__getCharInfo(inChar);
	uint8_t srcBytesPerLine = (fontInfo.charWidth + 7) / 8;
	uint16_t deflatedSize = fontInfo.charWidth * fontInfo.charHeight;
	uint8_t *deflatedChar;
	uint8_t *dstFrameBuffer;
	uint16_t i;

	/* param check for dstFrameBuffer buffer */
	if (frameBuffer == NULL)
		return -EINVAL;

	/* check destination numbers are within buffer boundaries */
	if (dstWidth > frameBufferWidth || dstHeight > frameBufferHeight)
		return -EINVAL;

	/* check if char fits to buffer; in width direction */
	if (dstWidth + fontInfo.charWidth > frameBufferWidth)
		return -ENOSPC;

	/* check if char fits to buffer; in height direction */
	if (dstHeight + fontInfo.charHeight > frameBufferHeight)
		return -ENOSPC;

	/* allocate space for deflating char */
	deflatedChar = malloc(deflatedSize);
	if (deflatedChar == NULL)
		return -ENOMEM;

	/* set destination framebuffer pointer */
	dstFrameBuffer = &frameBuffer[dstHeight * frameBufferWidth + dstWidth];

	/* deflate char from original char buffer */
	for (i = 0; i < deflatedSize; i++)
	{
		/* address the source's beginning */
		uint16_t sourceIdx = 0;

		/* address the source's line */
		uint16_t line = i / fontInfo.charWidth;
		sourceIdx += line * srcBytesPerLine;
		uint16_t relativeBitPos = i - (line *fontInfo.charWidth);

		/* address correct byte of line */
		sourceIdx += relativeBitPos / 8;
		relativeBitPos = relativeBitPos % 8;

		/* extract correct bit */
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



lib_font_consecutiveText_hdl lib_font__consecutiveText_Create(	lib_font__framebuffer_t fB,
																const char *textBuffer,
																const char textLen,
																uint8_t optCenterHoizontal,
																uint8_t optCenterVertical,
																uint8_t optFrameTheText)
{
	lib_font_consecutiveText_hdl hdl;

	/* frame buffer may not be NULL */
	if (fB.frameBuffer == NULL)
		return NULL;

	/* there must be a source buffer */
	if (textBuffer == NULL || textLen > LIB_FONT__CONSECUTIVETEXT__TEXTLENMAX)
		return NULL;

	/* create handle space */
	hdl = malloc(sizeof(struct lib_font_consecutiveText_handle));
	if (hdl == NULL)
		return NULL;

	/* create copy of source buffer */
	hdl->textBuffer = malloc(textLen);
	if (hdl->textBuffer == NULL)
	{
		free(hdl);
		return NULL;
	}
	memcpy(hdl->textBuffer, textBuffer, textLen);

	/* initialize the new data structure with user input */
	hdl->fB = fB;
	hdl->textLen = textLen;
	hdl->optCenterHoizontal = optCenterHoizontal;
	hdl->optCenterVertical = optCenterVertical;
	hdl->optFrameTheText = optFrameTheText;

	/* initialize the new data structure with meta information */
	hdl->intProgressInfo = 0;

	return hdl;
}



int lib_font__consecutiveText_Destroy(lib_font_consecutiveText_hdl *hdl)
{
	/* hdl param check */
	if (*hdl == NULL)
		return -EINVAL;

	/* internal buffer check */
	if ((*hdl)->textBuffer == NULL)
		return -EFAULT;

	free((*hdl)->textBuffer);
	free(*hdl);
	*hdl = NULL;

	/* all good */
	return 0;
}







/* Func: lib_font__consecutivePutTextToBuffer()
 * Desc: // todo
 *       Calculates the number of required pixels needed for a text provided in '*text'
 * Param-in c: // todo
 * Return: // todo
 * 0 nothing to print anymore
 * +1 continue with this procedure
 * -EFAULT: internal error
 */
// Todo: this function needs rework
int lib_font__consecutivePutTextToBuffer(lib_font_consecutiveText_hdl hdl)
{
	uint16_t availDotsX = hdl->fB.frameBufferWidth;
	uint16_t availDotsY = hdl->fB.frameBufferHeight;
	uint16_t curX = 0;
	uint16_t curY = 0;
	uint16_t numCharsToPrint;
	uint16_t i;

	/* flush whole framebuffer */
	memset(hdl->fB.frameBuffer, 0x00, hdl->fB.frameBufferWidth * hdl->fB.frameBufferHeight);

	/* put frame if requested and adjust info accordingly */
	if (hdl->optFrameTheText)
	{
		/* put the frame to the framebuffer */
		lib_font__drawFrame(hdl->fB);

		/* reduce the available dots for printing text */
		availDotsX -= 4;
		availDotsY -= 2;

		curX = 2;
		curY = 1;
	}

	/* eat up all non printable characters at the beginning of the current buffer */
	for (i = hdl->intProgressInfo; i < hdl->textLen; i++)
	{
		uint8_t c = hdl->textBuffer[hdl->intProgressInfo];
		if (lib_font__standard__isCharPrintable(c))
			break;
		hdl->intProgressInfo++;
	}

	/* is there anything to print at all? */
	if (hdl->intProgressInfo == hdl->textLen)
		return 0;

	/* find out how many chars can be put at all */
	if (lib_font__getNumOfCharsFitIn(availDotsX, &hdl->textBuffer[hdl->intProgressInfo], hdl->textLen - hdl->intProgressInfo, &numCharsToPrint) != 0)
		return -EFAULT;

	/* is this the last chunk, print it without further checking */
	if (hdl->intProgressInfo + numCharsToPrint == hdl->textLen)
		; // print as is
	else
	{
		/* if this range ending with a full word, print as is */
		if (lib_font__standard__isCharPrintable(hdl->textBuffer[hdl->intProgressInfo + numCharsToPrint + 1]) == 0)
		{
			; //print as is
		}

		/* check if this chunk is to be split to words */
		uint16_t lastNonPrintable = 0;
		for (i = 0; i < numCharsToPrint; i++)
			if (lib_font__standard__isCharPrintable(hdl->textBuffer[hdl->intProgressInfo + i]) == 0)
				lastNonPrintable = i;


		/* if this range defines a full word, print it as is */
		if (lastNonPrintable == 0)
		{
			; // print as is
		}
		/* otherwise print only up to the last word */
		else
		{
			numCharsToPrint = lastNonPrintable;
		}

	}

	/* calculate vertical centering if requested */
	if (hdl->optCenterVertical)
	{
		uint16_t bitsToAdjustVertically = (availDotsY - lib_font__standard__getFontHeight()) / 2;
		curY = bitsToAdjustVertically;
	}

	/* calculate horizontal centering if requested */
	if (hdl->optCenterHoizontal)
	{
		uint16_t requiredPixels = lib_font__calcRequiredPixels(&hdl->textBuffer[hdl->intProgressInfo], numCharsToPrint);
		uint16_t bitsToAdjustHorizontally = (availDotsX - requiredPixels) / 2;
		curX += bitsToAdjustHorizontally;
	}

	// point the internal variable to the next character to print
	// TODO!
	uint32_t charPutCounter;

	for (charPutCounter = 0; charPutCounter < numCharsToPrint; charPutCounter++)
	{
		uint8_t c = hdl->textBuffer[hdl->intProgressInfo];
		putCharToBuffer(hdl->fB.frameBuffer, hdl->fB.frameBufferWidth, hdl->fB.frameBufferHeight, curX, curY, c);
		hdl->intProgressInfo++;

		// notsonice:
		fontInfo_t fontInfo = lib_font__standard__getCharInfo(c);
		availDotsX -= fontInfo.charWidth;
		curX += fontInfo.charWidth;

		availDotsX -= 1; //space
		curX += 1;

	}
	if (hdl->intProgressInfo == hdl->textLen)
		return 0;

	return 1;
}






