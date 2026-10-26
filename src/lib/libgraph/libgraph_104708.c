#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { unsigned long* cur; } Packet;

/* Appends a (data, register) qword pair to a GIF packet. */
void sceGifPkAddGsAD(Packet* pkt, unsigned int reg, unsigned long data)
{
    unsigned long* p = pkt->cur;
    *p++ = data;
    *p++ = reg;
    pkt->cur = p;
}
