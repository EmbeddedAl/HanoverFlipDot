
#include <stdio.h>
#include <stdint.h>

#define LIB_SUPPORT__NIBBLE_HI(byte) 				((byte >> 4) & 0x0f)
#define LIB_SUPPORT__NIBBLE_LO(byte) 				((byte >> 0) & 0x0f)

#define LIB_SUPPORT__LOGLEVELFATAL 	255
#define LIB_SUPPORT__LOGLEVELERROR 	200
#define LIB_SUPPORT__LOGLEVELWARNG	100
#define LIB_SUPPORT__LOGLEVELINFOR	50
#define LIB_SUPPORT__LOGLEVELDEBUG	25

void lib_support__log(const char *libname, uint8_t level, const char *fmt, ...);


uint8_t lib_support__nibble2ascii(uint8_t in);
void lib_support__byte2ascii(uint8_t in, uint8_t *out);
