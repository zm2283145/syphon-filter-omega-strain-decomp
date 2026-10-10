#include "types.h"
typedef struct { unsigned int mt[625]; int mti; } R301;
extern R301 D_00490910;
void func_00301D08(unsigned int seed)
{
    unsigned int* p = D_00490910.mt;
    int i;
    D_00490910.mti = 0x26F;
    seed |= 1;
    *p++ = seed;
    for (i = 0x26F; i != 0; i--) {
        seed *= 69069;
        *p++ = seed;
    }
}