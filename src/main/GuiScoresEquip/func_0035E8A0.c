#include "types.h"
typedef struct { char pad[0x10]; float f10; } A2B35E;
typedef struct { A2B35E* b; float f; } A2A35E;
void func_0035E8A0(A2A35E* a, A2B35E* b, float x) {
    a->b = b;
    if (x < 0.0f) x = b->f10;
    a->f = x;
}