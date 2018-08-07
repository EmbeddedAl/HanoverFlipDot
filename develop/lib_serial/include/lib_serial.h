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

/* opaque pointer to a handle for the serial driver */
typedef struct lib_serial_handle *lib_serial_hdl;


/* Func: lib_serial_create()
 * Desc: Creates a handle to a specific serial port.
 *       On failure the pointer returned is NULL.
 *       The port will not be opened yet.
 *       This is the counter-function to lib_serial_destroy.
 * Param-in port: the port to be used for communication
 *                (NULL: behavior is undefined)
 * Return: the handle to be used for function calls to other API functions
 */
lib_serial_hdl lib_serial_create(const char *port);


/* Func: lib_serial_open()
 * Desc: Opens a port with a specific baud rate.
 *       This is the counter-function to lib_serial_close.
 * Param-in hdl: the handle used for communication
 * Param-in baudrate: baudrate to be used
 * Return: On success 0 is returned
 *         -EINVAL: invalid handle
 *         -EIO: I/O error accessing the handle
 *
 * Todo: This interface can be widened by
 * 	     bytesize, stopbits and parity
 */
int lib_serial_open(lib_serial_hdl hdl, uint32_t baudrate);


/* Func: lib_serial_close()
 * Desc: closes a port.
 *       This is the counter-function to lib_serial_open.
 * Param-in hdl: the handle used for communication
 * Return: On success 0 is returned
 */
int lib_serial_close(lib_serial_hdl hdl);


/* Func: lib_serial_destroy()
 * Desc: Destroys a handle
 *       This is the counter-function to lib_serial_create.
 * Param-in hdl: the handle used for communication
 * Return: On success 0 is returned
 *         -EINVAL: invalid handle
 */
int lib_serial_destroy(lib_serial_hdl *hdl);


/* Func: lib_serial_write()
 * Desc: Writes data to a serial port
 *       The function will send the data presented in 'data'
 *       to the seral port handed over in 'hdl'
 * Param-in hdl: the handle to be used for communication
 * Param-in data: pointer to the data buffer to be transmitted
 * Param-in len: length of bytes in data buffer to be transmitted
 * Return: On success 0 is returned
 *         -EINVAL: invalid handle
 *         -EIO: I/O error accessing the handle
 */
int lib_serial_write(lib_serial_hdl hdl, uint8_t *data, int len);


