/*
 * SFOGame/Source/humanIk: 3 files, 001CF090-001CF1F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CF090 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

int* std_vector_imp_cXformNodePtr_1_end(PtrVec* v) {
    return v->data + v->count;
}

void std_vector_cXformNodePtr_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

int* std_vector_imp_cXformNodePtr_1_begin(PtrVec* v) {
    return v->data;
}

int cArray_cXformNodePtr_ConstIterator_opMul(Word* w) {
    return w->value;
}

void cArray_cXformNodePtr_End(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void cArray_cXformNodePtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

/* End iterator of an array of 0x1D0-byte records. */
void std_vector_cBone_end(Elem1D0Iter* out, Vec1D0Array* v) {
    int count;
    Elem1D0* data;

    count = v->count;
    data = v->data;
    out->p = data + count;
}

Word* cArray_cBone_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_vector_cBone_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_001CF090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF090 */

/* merge_units: begin func_001CF160 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"
typedef struct { __int128 q; } V_F160;
typedef struct { int p; } It_F160;
typedef struct { char pad[0x50]; unsigned char a50; char pad51[0x3F]; V_F160 v90; char padA0[4]; int lA4[3]; } S_F160;
#if 0 /* merge_units */
extern void cArray_cXformNodePtr_Begin(It_F160* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_Begin(a0, a1) (cArray_cXformNodePtr_Begin((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_cXformNodePtr_End(It_F160* it, void* c);
#endif /* merge_units */
#define cArray_cXformNodePtr_End(a0, a1) (cArray_cXformNodePtr_End((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

extern int cArray_cXformNodePtr_ConstIterator_opNe(It_F160* a, It_F160* b);
#if 0 /* merge_units */
extern void** cArray_cXformNodePtr_ConstIterator_opMul(It_F160* it);
#endif /* merge_units */
#define cArray_cXformNodePtr_ConstIterator_opMul(a0) ((void * *)cArray_cXformNodePtr_ConstIterator_opMul((Word *)(a0))) /* merge_units */

extern void cXformNode_SetNeedsUpdate(void* p);
extern void cArray_cXformNodePtr_ConstIterator_opInc(It_F160* it);
#pragma opt_rotateloops off
void cXformNode_SetTranslation_ParentRelative(S_F160* o, V_F160* src)
{
    It_F160 b;
    It_F160 e;
    V4Copy(&o->v90, src);
    if (!o->a50) {
        It_F160* pe;
        o->a50 = 1;
        cArray_cXformNodePtr_Begin(&b, o->lA4);
        cArray_cXformNodePtr_End(&e, o->lA4);
        pe = &e;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&b, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&b));
            cArray_cXformNodePtr_ConstIterator_opInc(&b);
        }
    }
}
#pragma opt_rotateloops reset
#pragma peephole reset
#undef cArray_cXformNodePtr_Begin /* merge_units */
#undef cArray_cXformNodePtr_End /* merge_units */
#undef cArray_cXformNodePtr_ConstIterator_opMul /* merge_units */
static inline void merge_flush_func_001CF160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF160 */

/* merge_units: begin func_001CF1F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x60]; float m[12]; } Src1CF;
extern void cMatrix_ctor_float_float_float_float_etc(Mtx44* m, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13,
                      float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);

/* Builds a 4x4 matrix from the 3x4 block at +0x60 of src, with (0, 0, 0, 1) as the last column. */
void cXformNode_GetRotationMatrix_ParentRelative(Mtx44* out, Src1CF* s)
{
    cMatrix_ctor_float_float_float_float_etc(out, s->m[0], s->m[1], s->m[2], s->m[3], s->m[4], s->m[5], s->m[6], s->m[7],
              s->m[8], s->m[9], s->m[10], s->m[11], 0.0f, 0.0f, 0.0f, 1.0f);
}
static inline void merge_flush_func_001CF1F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CF1F0 */
