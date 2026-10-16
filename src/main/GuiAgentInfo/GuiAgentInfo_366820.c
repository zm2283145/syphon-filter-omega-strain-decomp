/*
 * main/GuiAgentInfo: 6 files, 00366820-00366E10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00366820 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_assign.h"

/* Copy a range of 60-byte elements by assignment. */
DEFINE_COPY_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_ASSIGN(func_00366820, Elem60, func_001BECC0)
#pragma pop /* merge_units */
/* merge_units: end func_00366820 */

/* merge_units: begin func_00366890 */
#pragma push /* merge_units */
typedef struct { char b[0x18]; } Part18;
typedef struct { char b[8]; } Part8;
typedef struct { int unk0; float f[5]; Part18 a; Part8 b; unsigned char flag; } Obj366;
extern void func_001BED80(Part18* dst, Part18* src);
extern float func_001BED70(Part8* p);
extern void func_001BED50(Part8* dst, Part18* a, float v);

/* Copies src into dst field by field; returns dst. */
Obj366* func_00366890(Obj366* dst, Obj366* src)
{
    dst->f[0] = src->f[0];
    dst->f[1] = src->f[1];
    dst->f[2] = src->f[2];
    dst->f[3] = src->f[3];
    dst->f[4] = src->f[4];
    func_001BED80(&dst->a, &src->a);
    func_001BED50(&dst->b, &dst->a, func_001BED70(&src->b));
    dst->flag = src->flag;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00366890 */

/* merge_units: begin func_00366920 */
#pragma push /* merge_units */
typedef struct { int a[4]; float f; } T_00366920;
typedef struct { T_00366920* t; float v; } D_00366920;
void func_00366920(D_00366920* d, T_00366920* t, float v) {
    d->t = t;
    if (v < 0.0f) v = t->f;
    d->v = v;
}
#pragma pop /* merge_units */
/* merge_units: end func_00366920 */

/* merge_units: begin func_00366940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

float func_00366940(Float6* self) {
    return self->v[1];
}

/* Float6 copy. */
Float6* func_00366950(Float6* dst, Float6* src) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = src->v[3];
    dst->v[4] = src->v[4];
    dst->v[5] = src->v[5];
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_00366940 */

/* merge_units: begin func_00366990 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

DEFINE_VECTOR_INSERT_FILL_OBJ(func_00366990, 0x3C, 0x199999, 0xCCCCC, D_004BBAA0, D_0049ECF8, 0x5C, func_00139BC0, AnimChannel_CopyCtor, func_001BF2E0, func_001BF280, func_001BF240, func_001BFA50)
#pragma pop /* merge_units */
/* merge_units: end func_00366990 */

/* merge_units: begin func_00366E10 */
#pragma push /* merge_units */
void func_00366E10(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00366E10 */
