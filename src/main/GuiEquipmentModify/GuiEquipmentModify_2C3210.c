/*
 * main/GuiEquipmentModify: 6 files, 002C3210-002C3800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C3210 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "range_copy_assign.h"

/* Copy a range of 60-byte elements by assignment. */
DEFINE_COPY_ELEMENT(Elem60, 60)
DEFINE_RANGE_COPY_ASSIGN(func_002C3210, Elem60, func_001BECC0)
#pragma pop /* merge_units */
/* merge_units: end func_002C3210 */

/* merge_units: begin func_002C3280 */
#pragma push /* merge_units */
typedef struct { char data[0x18]; } Sub002C3280;
typedef struct { int unk0; float f[5]; Sub002C3280 sub; char sub30[8]; unsigned char flag; } Obj002C3280;
extern void func_001BED80(Sub002C3280* dst, Sub002C3280* src);
extern float func_001BED70(void* src);
extern void func_001BED50(void* dst, Sub002C3280* sub, float value);
/* Copy-assign. */
Obj002C3280* func_002C3280(Obj002C3280* dst, Obj002C3280* src)
{
    dst->f[0] = src->f[0];
    dst->f[1] = src->f[1];
    dst->f[2] = src->f[2];
    dst->f[3] = src->f[3];
    dst->f[4] = src->f[4];
    func_001BED80(&dst->sub, &src->sub);
    func_001BED50(dst->sub30, &dst->sub, func_001BED70(src->sub30));
    dst->flag = src->flag;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C3280 */

/* merge_units: begin func_002C3310 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } T2C3310;
typedef struct { T2C3310* t; float v; } O2C3310;
void func_002C3310(O2C3310* o, T2C3310* t, float x) {
    o->t = t;
    if (x < 0.0f) {
        x = t->f10;
    }
    o->v = x;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C3310 */

/* merge_units: begin func_002C3330 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

/* Returns the float at +4 (second float of the record). */
float func_002C3330(Float6* self) {
    return self->v[1];
}

/* Float6 copy (assignment). */
Float6* func_002C3340(Float6* dst, Float6* src) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = src->v[3];
    dst->v[4] = src->v[4];
    dst->v[5] = src->v[5];
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C3330 */

/* merge_units: begin func_002C3380 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

DEFINE_VECTOR_INSERT_FILL_OBJ(Vector_Insert_2C3380, 0x3C, 0x199999, 0xCCCCC, D_004AC640, D_0049ECF8, 0x5C, Mem_PlacementNew, AnimChannel_CopyCtor, func_001BF2E0, func_001BF280, func_001BF240, func_001BFA50)
#pragma pop /* merge_units */
/* merge_units: end func_002C3380 */

/* merge_units: begin func_002C3800 */
#pragma push /* merge_units */
void func_002C3800(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_002C3800 */
