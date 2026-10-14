/*
 * main/ska: range (2 files, 003AF1D0-003AF280)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003AF1D0 */
#pragma push /* merge_units */
/* 32-byte temporary transform/curve value. */
typedef struct Temp32 {
    Q a;
    Q b;
} Temp32;

typedef struct AnimRootBase {
    char channel0[0x20];
    char ref20[0x10];
    char channel30[0x20];
    char channel50[0x20];
    char ref70[0x10];
    char channel80[0x20];
    unsigned char flagA0;
    unsigned char flagA1;
    unsigned char flagA2;
} AnimRootBase;

extern void Root_BaseConstruct(Temp32* t);
extern void VecPair_Copy(void* channel, Temp32* t);
extern void* Vec4_GetZero(void);
extern void Vec4_Assign(void* dst, void* src);

/* Constructs the base part of an animation root: four channels, two default refs, flags cleared. */
AnimRootBase* AnimRoot_ConstructBase(AnimRootBase* self) {
    Temp32 t4, t3, t2, t1;
    Root_BaseConstruct(&t1);
    VecPair_Copy(self->channel0, &t1);
    Vec4_Assign(self->ref20, Vec4_GetZero());
    Root_BaseConstruct(&t2);
    VecPair_Copy(self->channel30, &t2);
    Root_BaseConstruct(&t3);
    VecPair_Copy(self->channel50, &t3);
    Vec4_Assign(self->ref70, Vec4_GetZero());
    Root_BaseConstruct(&t4);
    VecPair_Copy(self->channel80, &t4);
    self->flagA0 = 0;
    self->flagA1 = 0;
    self->flagA2 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AF1D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AF1D0 */

/* merge_units: begin func_003AF280 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern int func_003B8230(int, int);

Word* func_003AF280(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void* func_003AF290(char* self) {
    return self + 8;
}

int func_003AF2A0(int a0, int a1) {
    return func_003B8230(a0, a1);
}

Rel* func_003AF2B0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AF280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AF280 */
