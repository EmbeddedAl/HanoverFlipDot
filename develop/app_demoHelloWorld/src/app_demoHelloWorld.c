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
 *  Creation: 2018-08-16, @EmbeddedAl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_font.h"
#include "lib_hanover.h"
#include "lib_serial.h"
#include "lib_support.h"

/* static variables to store the arguments passed by the user */
static const char *s_ArgPort;
static uint32_t    s_ArgBaud;
static uint16_t    s_ArgWidth;
static uint16_t    s_ArgHeight;
static uint8_t     s_ArgAddr;
static const char *s_ArgInput;

/* static variables and handles for the application */
lib_serial_hdl          s_hdl_serial;
lib_hanover_hdl         s_hdl_hanover;
lib_font__framebuffer_t s_lib_font_fb;

static int app_demo_HelloWorld__readParams(int argc, char *argv[])
{
	// parameter sanity
	if (argc != 7)
	{
		printf("Incorrect usage:\r\n");
		printf(" Usage Params: PORT BAUD WIDTH HEIGTH ADDRESS TEXT\r\n");
		printf(" Example Windows: app.exe COM8 4800 112 16 1 \"Text To Print\"\r\n");
		printf(" Example Windows: ./app /dev/ser0 4800 112 16 1 \"Text To Print\"\r\n");
		printf(" Typical for small display    28x13 @3 \r\n");
		printf(" Typical for med.  display    112x16 @1 \r\n");
		return 1;
	}

	s_ArgPort   = argv[1];
	s_ArgBaud   = atoi(argv[2]);
	s_ArgWidth  = atoi(argv[3]);
	s_ArgHeight = atoi(argv[4]);
	s_ArgAddr   = atoi(argv[5]);
	s_ArgInput  = argv[6];

	printf("Entering main() on port %s,%u with %ux%u@%u (WxH@Addr)\r\n", s_ArgPort, s_ArgBaud, s_ArgWidth, s_ArgHeight, s_ArgAddr);

	return 0;
}

static int app_demo_HelloWorld__initialize(void)
{
	/* create and open serial port */
	s_hdl_serial = lib_serial_create(s_ArgPort);
	printf("Serial handle created (%p) on %s\r\n", s_hdl_serial, s_ArgPort);

	if (lib_serial_open(s_hdl_serial, s_ArgBaud) != 0)
		return 1;
	printf("Serial port opened on baud %i\r\n", s_ArgBaud);

	/* create and open display interface instance  */
	s_hdl_hanover = lib_hanover__create(s_hdl_serial, s_ArgAddr, s_ArgWidth, s_ArgHeight);
	printf("lib hanover handle created (%p) \r\n", s_hdl_hanover);

	/* prepare the frame buffer variable */
	s_lib_font_fb.frameBufferHeight = s_ArgHeight;
	s_lib_font_fb.frameBufferWidth  = s_ArgWidth;
	s_lib_font_fb.frameBuffer = malloc(s_ArgHeight * s_ArgWidth);
	if (s_lib_font_fb.frameBuffer == NULL)
		return 1;

	return 0;
}

static int app_demo_HelloWorld__shutdown(void)
{
	/* free the framebuffer */
	if (s_lib_font_fb.frameBuffer)
		free(s_lib_font_fb.frameBuffer);

	/* destroy display instance */
	lib_hanover__destroy(&s_hdl_hanover);

	/* destroy serial port */
	lib_serial_close(s_hdl_serial);
	lib_serial_destroy(&s_hdl_serial);

	return 0;
}

static int app_demo_HelloWorld__writeFbToHanoverWrapper(uint8_t invertColor)
{
	return lib_hanover__writePayloadRawFormat(s_hdl_hanover,
			                                  s_lib_font_fb.frameBuffer,
											  s_lib_font_fb.frameBufferHeight * s_lib_font_fb.frameBufferWidth,
											  s_lib_font_fb.frameBufferWidth,
											  s_lib_font_fb.frameBufferHeight,
											  invertColor);
}

static int app_demo_HelloWorld__writeText(void)
{
	lib_font_consecutiveText_hdl lib_font_cThdl;
	int cTstatus;
	uint8_t invertColor = 0;

	/* initialize the consecutiveText handle */
	lib_font_cThdl = lib_font__consecutiveText_Create(s_lib_font_fb, s_ArgInput, strlen(s_ArgInput), 1, 0, 1);

	/* print as long as there is something left */
	do {
		/* put next chunk of text to framebuffer */
		cTstatus = lib_font__consecutivePutTextToBuffer(lib_font_cThdl);

		/* break on error */
		if (cTstatus < 0)
			break;

		/* output the framebuffer */
		if (app_demo_HelloWorld__writeFbToHanoverWrapper(invertColor) != 0)
			break;

		/* sleep a while for the next chunk of data */
		lib_support__sleep(1000);

	} while(cTstatus != 0);

	/* destroy the consecutiveText handle */
	lib_font__consecutiveText_Destroy(&lib_font_cThdl);

	/* sleep additional time before flushing the display */
	lib_support__sleep(3000);

	/* flush buffer */
	memset(s_lib_font_fb.frameBuffer, 0x00, s_lib_font_fb.frameBufferHeight * s_lib_font_fb.frameBufferWidth);
	app_demo_HelloWorld__writeFbToHanoverWrapper(invertColor);

	return 0;
}



int main(int argc, char *argv[])
{
	/* read user parameters */
	if (app_demo_HelloWorld__readParams(argc, argv) != 0)
		return 1;

	/* init */
	if (app_demo_HelloWorld__initialize() != 0)
		return 1;

	/* work */
	app_demo_HelloWorld__writeText();

	/* shutdown */
	if (app_demo_HelloWorld__shutdown() != 0)
		return 1;

	return 0;
}
