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
#include "lib_font__internal.h"

/* Func: lib_font__standard__getFontHeight()
 * Desc: Returns the font height
 * Return: the font height
 */
uint16_t lib_font__standard__getFontHeight(void);

/* Func: lib_font__standard__getCharInfo()
 * Desc: Returns the font info for the char requested
 * 		 Unsupported ascii codes will be treated as '?'.
 * Param-in inChar: the character that is requested
 * Return: the corresponding fontInfo_t type for the char
 */
fontInfo_t lib_font__standard__getCharInfo(char inChar);
