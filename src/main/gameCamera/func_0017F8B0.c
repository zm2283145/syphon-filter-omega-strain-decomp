#include "types.h"
#pragma peephole off
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { unsigned char on; char pad[0xF]; V4 a; V4 b; } Obj;
extern signed char D_004E1D88;
extern V4 D_004E1D90;
/* Inlined Vec4_GetZero (Vec4_GetZero): lazily zeroed shared vector. */
static inline V4* Vec4_Zero(void) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return &D_004E1D90;
}
/* Sets the flag and clears both vectors. */
Obj* func_0017F8B0(Obj* o) {
    o->on = 1;
    o->a = *Vec4_Zero();
    o->b = *Vec4_Zero();
    return o;
}

