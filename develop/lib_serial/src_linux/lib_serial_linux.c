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
#include <errno.h>


/* the handle definition for this implementation */
struct lib_serial_handle{
	uint32_t dummy;
};


lib_serial_hdl lib_serial_create(const char *port)
{
	lib_serial_hdl hdl = NULL;

	/* param check */
	if (port == NULL)
		return NULL;

	/* create handle space */
	hdl = malloc(sizeof(struct lib_serial_handle));
	if (hdl == NULL)
		return NULL;

	return hdl;
}


int lib_serial_open(lib_serial_hdl hdl, uint32_t baudrate)
{
	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	/* success */
	return 0;
}


int lib_serial_close(lib_serial_hdl hdl)
{
	return 0;
}


int lib_serial_destroy(lib_serial_hdl *hdl)
{
	/* hdl param check */
	if (*hdl == NULL)
		return -EINVAL;

	/* free allocated space and declare handle as invalid */
	free(*hdl);
	*hdl = NULL;

	/* all good */
	return 0;
}


int lib_serial_write(lib_serial_hdl hdl, uint8_t *data, int len)
{
	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	return 0;
}
