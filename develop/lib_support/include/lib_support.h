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
 *  Creation: 2018-07-20, @EmbeddedAl
 */


/* includes */
#include <stdio.h>
#include <stdint.h>

/* macros to extract a single nibble (4bit) from a full byte (8bit) */
#define LIB_SUPPORT__NIBBLE_HI(byte) 				((byte >> 4) & 0x0f)
#define LIB_SUPPORT__NIBBLE_LO(byte) 				((byte >> 0) & 0x0f)

/* defines for the logging interface of lib_support */
#define LIB_SUPPORT__LOGLEVELFATAL 	255
#define LIB_SUPPORT__LOGLEVELERROR 	200
#define LIB_SUPPORT__LOGLEVELWARNG	100
#define LIB_SUPPORT__LOGLEVELINFOR	50
#define LIB_SUPPORT__LOGLEVELDEBUG	25 


/* Func: lib_support__log()
 * Desc: Use this function in your source code to log stuff.
 *       Different implementations allow to log to different locations.
 *       Having different libnames and log levels allow to filter the log.
 * Param-in libname: the library name that is responsible for this log entry.
 *                   (NULL: behavior is undefined)
 * Param-in level: the log level of this log entry (see helping defines in this file).
 * Param-in fmt,...: a format string for the actual log message (see ANSI-C standard / stdio.h / printf).
 * Return: void
 */
void lib_support__log(const char *libname, uint8_t level, const char *fmt, ...);


/* Func: lib_support__nibble2ascii()
 * Desc: This function converts a nibble (4bit) to an ASCII character.
 *       e.g. 0x00 => 0x30 = ASCII '0'
 *            0x01 => 0x31 = ASCII '1'
 *            ...
 *            0x09 => 0x39 = ASCII '9'
 *            0x0A => 0x41 = ASCII 'A'
 *            0x0B => 0x42 = ASCII 'B'
 *            ...
 *            0x0F => 0x46 = ASCII 'F' 
 *       Only lower nibble will be considered
 *       Bits of higher nibble will be ignored:
 *       e.g. 0x3B => 0x42 = ASCII 'B'
 * Param-in in: the nibble to be converted
 * Return: uint8_t the ASCII character converted from 'in'
 */
uint8_t lib_support__nibble2ascii(uint8_t in);


