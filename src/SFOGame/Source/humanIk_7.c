/*
 * SFOGame/Source/humanIk: 2 files, 001CEE00-001CEE20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CEE00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cWeaponSlotPair_cIkTarget_LeftRight_end(Iter* out, Tree* t) {
    out->p = &t->header;
}
static inline void merge_flush_func_001CEE00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEE00 */

/* merge_units: begin func_001CEE20 */
#pragma push /* merge_units */
typedef struct { int* p; } F8It_1CE;
typedef struct { float m[4][4]; } F8Mtx_1CE;
typedef struct { char pad0[0x50]; unsigned char dirty; char pad51[0xF]; F8Mtx_1CE basis; char padA0[0x4]; char kids[4]; } F8Bone_1CE;
extern void cArray_cXformNodePtr_Begin(F8It_1CE* out, void* v);
extern void cArray_cXformNodePtr_End(F8It_1CE* out, void* v);
extern int cArray_cXformNodePtr_ConstIterator_opNe(F8It_1CE* a, F8It_1CE* b);
extern int* cArray_cXformNodePtr_ConstIterator_opMul(F8It_1CE* it);
extern void cXformNode_SetNeedsUpdate(int child);
extern F8It_1CE* cArray_cXformNodePtr_ConstIterator_opInc(F8It_1CE* it);
void cXformNode_SetRotationMatrix_ParentRelative(F8Bone_1CE* b, F8Mtx_1CE* m)
{
    b->basis.m[0][0] = m->m[0][0];
    b->basis.m[0][1] = m->m[0][1];
    b->basis.m[0][2] = m->m[0][2];
    b->basis.m[1][0] = m->m[1][0];
    b->basis.m[1][1] = m->m[1][1];
    b->basis.m[1][2] = m->m[1][2];
    b->basis.m[2][0] = m->m[2][0];
    b->basis.m[2][1] = m->m[2][1];
    b->basis.m[2][2] = m->m[2][2];
    b->basis.m[0][3] = m->m[0][3];
    b->basis.m[1][3] = m->m[1][3];
    b->basis.m[2][3] = m->m[2][3];
    if (!b->dirty) {
        F8It_1CE it;
        F8It_1CE end;
        F8It_1CE* pe;
        b->dirty = 1;
        cArray_cXformNodePtr_Begin(&it, b->kids);
        cArray_cXformNodePtr_End(&end, b->kids);
        pe = &end;
        while (cArray_cXformNodePtr_ConstIterator_opNe(&it, pe)) {
            cXformNode_SetNeedsUpdate(*cArray_cXformNodePtr_ConstIterator_opMul(&it));
            cArray_cXformNodePtr_ConstIterator_opInc(&it);
        }
    }
}
static inline void merge_flush_func_001CEE20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CEE20 */
