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
#include <stdlib.h>
#include <errno.h>

#include <stdio.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions 	   */
#include <errno.h> /* ERROR Number Definitions           */

/* the handle definition for this implementation */
struct lib_serial_handle{
	int fd;
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

	/* open port and store file descriptor to it */
	hdl->fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);

	/* error checking of open() */
	if(hdl->fd == -1)
	{
		free(hdl);
		return NULL;
	}

	return hdl;
}


int lib_serial_open(lib_serial_hdl hdl, uint32_t baudrate)
{
	struct termios portSettings;

	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	/* get current settings */
	tcgetattr(hdl->fd, &portSettings);

	/* set speed in both directions */
	// todo: map input to constants?
	cfsetispeed(&portSettings,B4800);
	cfsetospeed(&portSettings,B4800);

	/* no parity */
	portSettings.c_cflag &= ~PARENB;

	/* 1 stop bit (flag for 2 is cleared) */
	portSettings.c_cflag &= ~CSTOPB;

	/* 8 bits */
	portSettings.c_cflag &= ~CSIZE;
	portSettings.c_cflag |=  CS8;

	/* no flow control */
	portSettings.c_cflag &= ~CRTSCTS;

	 /* Enable receiver,Ignore Modem Control lines */
	portSettings.c_cflag |= CREAD | CLOCAL;

	/* Disable XON/XOFF flow control both i/p and o/p */
	portSettings.c_iflag &= ~(IXON | IXOFF | IXANY);

	/* Non cannonical mode */
	portSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);

	/* No Output Processing */
	portSettings.c_oflag &= ~OPOST;

	/* Set the attributes to the termios structure */
	if((tcsetattr(hdl->fd,TCSANOW,&portSettings)) != 0)
	    return -EIO;

	/* success */
	return 0;
}


int lib_serial_close(lib_serial_hdl hdl)
{
	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	/* close port */
	close(hdl->fd);

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
	int bytesWritten;

	/* hdl param check */
	if (hdl == NULL)
		return -EINVAL;

	/* write */
	bytesWritten = write(hdl->fd, data, len);

	/* check return */
	if (bytesWritten != len)
		return -EIO;

	return 0;
}
