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
#include "lib_support.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void lib_support__log(const char *libname, uint8_t level, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    /* start */
    printf("LOG: ");

    /* lib_name@level */
    printf("%7s@%03u", libname, level);

    /* user message */
    printf(fmt, args);

    va_end(args);
}

uint8_t lib_support__nibble2ascii(uint8_t in)
{
    /* use low nibble received and convert it to ASCII */
    in = (in & 0x0f) + 0x30;

    /* if it is from 'A to F' increment it accordingly */
    if (in > 0x39)
        in += 7;

    return in;
}
