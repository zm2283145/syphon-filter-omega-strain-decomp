/*
 * main/particle: range (2 files, 0039EEF0-0039EF10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0039EEF0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void func_0039EEF0(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        vsubw.w vf3, vf0, vf0w
        sqc2 vf3, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0039EEF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0039EEF0 */

/* merge_units: begin func_0039EF10 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Info9EF10 {
    char pad[0x8F4];
    int busy;                   /* 0x8F4 */
};

class Obj9EF10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Info9EF10* GetInfo();   /* vtable +0x14 */
    char pad04[0x60 - 0x04];
    float delay;                /* 0x60 */
    float last;                 /* 0x64 */
    char pad68[0x74 - 0x68];
    int owner;                  /* 0x74 */
    char pad78[0x16C - 0x78];
    unsigned char ready;        /* 0x16C */
};

extern "C" unsigned char ShatterEmitter_IsDead(Obj9EF10* self, float now)
{
    unsigned char r;
    if (self->owner == 0) r = self->ready;
    else r = !(self->GetInfo()->busy != 0) && now - self->last > self->delay;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0039EF10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0039EF10 */
