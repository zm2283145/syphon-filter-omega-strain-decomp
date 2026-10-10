#include "types.h"
typedef struct { char pad[0x10]; float f10; } A5_003650B0_B;
typedef struct { char pad[0x28]; float f28; char pad2[4]; A5_003650B0_B* b; float f34; } A5_003650B0;
int func_003650B0(A5_003650B0* p) {
    return p->f34 == p->b->f10 && p->f28 > 0.0f;
}