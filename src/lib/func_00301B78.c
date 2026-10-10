#include "types.h"

/* compiler: ee-gcc 2.95 -O2 -G0 (check.py --gcc) */

/* Writes an unsigned 16-bit value big-endian into buf; returns 2 if buf is NULL, else 0. */
int func_00301B78(unsigned char* buf, unsigned short value)
{
    int ret = 2;
    unsigned char hi = value >> 8;
    if (buf != 0) {
        buf[0] = hi;
        buf[1] = value;
        ret = 0;
    }
    return ret;
}
