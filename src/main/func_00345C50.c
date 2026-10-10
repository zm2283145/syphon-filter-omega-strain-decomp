#include "types.h"
typedef struct { char pad[0x10]; float f10; } A1_T;
typedef struct { A1_T* p; float f4; } A1_S;
void func_00345C50(A1_S* o, A1_T* p, float x) {
    o->p = p;
    if (x < 0.0f) x = p->f10;
    o->f4 = x;
}