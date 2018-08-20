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
#include <stdio.h>
#include <stdint.h>


typedef struct lib_font__framebuffer
{
	uint8_t *frameBuffer;
	uint16_t frameBufferWidth;
	uint16_t frameBufferHeight;
} lib_font__framebuffer_t;

/* Func: lib_font__putCharToFrameBuffer()
 * Desc: Puts a desired character to a framebuffer at a certain position
 * Param-in/out frameBuffer: the start address of the framebuffer
 * Param-in frameBufferWidth: the total width of the framebuffer (in bytes)
 * Param-in frameBufferHeight: the total height of the framebuffer (in bytes)
 * Param-in dstWidth: the width position on where to put the character
 * Param-in dstHeight: the height position on where to put the character
 * Param-in inChar: the character that is to put to the framebuffer
 * Return: On success 0 is returned
 *         -EINVAL: dstFrameBuffer buffer NULL
 *         -EINVAL: width and height parameter are insane
 *         -ENOSPC: frameBuffer at desired position is too small for the character
 *         -ENOMEM: temporary memory allocation failed (internal error)
 */
int lib_font__putCharToFrameBuffer(uint8_t *frameBuffer, uint16_t frameBufferWidth, uint16_t frameBufferHeight, uint16_t dstWidth, uint16_t dstHeight, char inChar);

/* opaque pointer to a handle for outputting consecutive text */
typedef struct lib_font_consecutiveText_handle *lib_font_consecutiveText_hdl;

/* Func: lib_font__consecutiveText_Create()
 * Desc: // todo
 *       // frame buffer must be valid during lifetime of this object
 *       // textBuffer will be copied internally and may be invalidated after Create-Call
 *       // // TODO: develop concept for sanity and length checks
 * Param-in framebuffer: // todo
 * Param-in textBuffer: // todo
 * Param-in textLen: // todo
 * Param-in optCenterHoizontal: // todo
 * Param-in optCenterVertical: // todo
 * Param-in optFrameTheText: // todo
 * Return: // todo
 */
lib_font_consecutiveText_hdl lib_font__consecutiveText_Create(	lib_font__framebuffer_t framebuffer,
																const char *textBuffer,
																const char textLen,
																uint8_t optCenterHoizontal,
																uint8_t optCenterVertical,
																uint8_t optFrameTheText);

/* Func: lib_font__consecutivePutTextToBuffer()
 * Desc: // todo
 * Param-in hdl: // todo
 * Return: // todo
 */
int lib_font__consecutivePutTextToBuffer(lib_font_consecutiveText_hdl hdl);

/* Func: lib_font__consecutiveText_Destroy()
 * Desc: // todo
 * Param-in hdl: // todo
 * Return: // todo
 */
int lib_font__consecutiveText_Destroy(lib_font_consecutiveText_hdl *hdl);

