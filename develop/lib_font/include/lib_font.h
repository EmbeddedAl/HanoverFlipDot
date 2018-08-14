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


/* Func: putCharToFrameBuffer()
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
int putCharToFrameBuffer(uint8_t *frameBuffer, uint16_t frameBufferWidth, uint16_t frameBufferHeight, uint16_t dstWidth, uint16_t dstHeight, char inChar);
