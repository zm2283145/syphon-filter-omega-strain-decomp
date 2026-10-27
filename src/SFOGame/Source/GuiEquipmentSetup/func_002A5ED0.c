#include "types.h"
typedef struct { char pad[0x10]; float f10; } A5_002A5ED0_B;
typedef struct { A5_002A5ED0_B* b; float f; } A5_002A5ED0_A;
void func_002A5ED0(A5_002A5ED0_A* a, A5_002A5ED0_B* b, float f) {
    a->b = b;
    if (f < 0.0f) f = b->f10;
    a->f = f;
}