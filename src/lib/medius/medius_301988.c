#include "types.h"
/* Stores a 16-bit value little-endian into two bytes; returns 2 when p is NULL. */
int rt_msg_set_u2byte(unsigned char* p, unsigned short v)
{
    int ret = 2;
    unsigned char hi = v >> 8;
    if (p != 0) {
        p[0] = v;
        p[1] = hi;
        ret = 0;
    }
    return ret;
}
