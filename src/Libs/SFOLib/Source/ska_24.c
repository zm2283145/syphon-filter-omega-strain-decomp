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

extern void cQuatVec_GetUnit(Temp32* t);
extern void cQuatVec_ctor_cQuatVecR(void* channel, Temp32* t);
extern void* cVector_GetZero(void);
extern void cVector_ctor_cVectorR(void* dst, void* src);

/* Constructs the base part of an animation root: four channels, two default refs, flags cleared. */
AnimRootBase* cSkaAnimAnchor_TreeNodeData_ctor_void(AnimRootBase* self) {
    Temp32 t4, t3, t2, t1;
    cQuatVec_GetUnit(&t1);
    cQuatVec_ctor_cQuatVecR(self->channel0, &t1);
    cVector_ctor_cVectorR(self->ref20, cVector_GetZero());
    cQuatVec_GetUnit(&t2);
    cQuatVec_ctor_cQuatVecR(self->channel30, &t2);
    cQuatVec_GetUnit(&t3);
    cQuatVec_ctor_cQuatVecR(self->channel50, &t3);
    cVector_ctor_cVectorR(self->ref70, cVector_GetZero());
    cQuatVec_GetUnit(&t4);
    cQuatVec_ctor_cQuatVecR(self->channel80, &t4);
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


extern int std_vector_imp_cSkaAnimAnchorListEntry_reserve(int, int);

Word* cString4_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void* std_vector_deleter_cString4_data(char* self) {
    return self + 8;
}

int std_vector_cSkaAnimAnchorListEntry_reserve(int a0, int a1) {
    return std_vector_imp_cSkaAnimAnchorListEntry_reserve(a0, a1);
}

Rel* std_vector_cSkaAnimAnchorListEntry_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AF280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AF280 */
