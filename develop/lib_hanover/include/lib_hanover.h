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
#include <stdio.h>
#include <stdint.h>
#include "lib_serial.h"



/* opaque pointer to a handle for the Hanover driver */
typedef struct lib_hanover_handle *lib_hanover_hdl;



/* Func: lib_hanover__create()
 * Desc: Creates a handle to a Hanover display driver.
 *       On failure the pointer returned is NULL.
 *       This is the counter-function to lib_hanover__destroy.
 * Param-in serial_hdl: the serial_hdl to be used for communication
 * Param-in address: bus-address of the display to be addressed
 * Param-in width: width of the display in pixel
 * Param-in height: height of the display in pixel
 * Return: the handle to be used for function calls
 */
lib_hanover_hdl lib_hanover__create(lib_serial_hdl serial_hdl, uint8_t address, uint16_t width, uint16_t height);



/* Func: lib_hanover__destroy()
 * Desc: Destroys a handle
 *       This is the counter-function to lib_hanover__create.
 * Param-in hdl: the handle used for display communication
 * Return: On success 0 is returned
 *         -EINVAL: invalid handle
 *         -EFAULT: internal error
 */
int lib_hanover__destroy(lib_hanover_hdl *hdl);



/* Func: lib_hanover__writeHanoverDataFormat()
 * Desc: Writes display content in Hanover data format to display.
 * 		 The function will put the display content in Hanover format
 * 		 from 'data' in a frame of the Hanover frame format
 * 		 (header + 'data' + CRC).
 * 		 The CRC will also calculated by this function.
 * 		 The finally framed buffer will be transmitted
 * 		 to the serial port of the handle.
 * Param-in hdl: the handle to be used for display communication
 * Param-in data: pointer to the raw data buffer to be transmitted
 * Param-in len: length of bytes in data buffer to be transmitted
 * Return: On success 0 is returned
 *         -EINVAL: invalid handle
 *         -ENOEXEC: incorrect buffer length for this display
 *         -EFAULT: unknown internal error
 *         -EIO: I/O error accessing the communication handle
 */
int lib_hanover__writeHanoverDataFormat(lib_hanover_hdl hdl, uint8_t *data, uint32_t len);
