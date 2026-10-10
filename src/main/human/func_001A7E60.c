#include "types.h"
typedef struct { char pad[0x10]; int mode; int bits[1]; } Physical;
static inline unsigned char Pcm_Test(Physical* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void Physical_ClearModeBit(Physical* p, int bit)
{
    int i;
    p->bits[bit / 32] &= ~(1 << (bit & 31));
    for (i = 12; i >= 0 && !Pcm_Test(p, i); i--) {
    }
    if (!Pcm_Test(p, i)) {
        p->mode = -1;
    } else {
        p->mode = i;
    }
}