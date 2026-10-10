#include "types.h"
typedef struct { char pad[0x10]; int mode; int bits[1]; } E7Phys;
static inline unsigned char E7PTest(E7Phys* p, int n)
{
    return ((p->bits[n / 32] >> (n & 31)) & 1) != 0;
}
void Physical_SetModeBit(E7Phys* p, int bit)
{
    int i;
    p->bits[bit / 32] |= 1 << (bit & 31);
    for (i = 12; i >= 0 && !E7PTest(p, i); i--) {
    }
    if (!E7PTest(p, i)) {
        p->mode = -1;
    } else {
        p->mode = i;
    }
}