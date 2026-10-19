/*
 * main/materialProperties: 7 files, 00409520-00409940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00409520 */
#pragma push /* merge_units */
#include "types.h"
extern void func_00408EA0(void* self);
extern void operator_delete(void* p);
/* Deleting destructor: run the member destructor, then delete. */
void* func_00409520(void* self, short del)
{
    if (self) {
        func_00408EA0(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00409520 */

/* merge_units: begin func_00409580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

Unk409580* func_00409580(Unk409580* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk08 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00409580 */

/* merge_units: begin func_004095A0 */
#pragma push /* merge_units */
typedef struct { int a[4]; } S409;
typedef struct { int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c; float f30; unsigned char b34; } O409;
extern int String_CompareNoCase(char*, char*);
extern void String_CtorCStr_13B480(S409*, char*);
extern void String_AssignString(void*, S409*);
extern void String_Dtor(S409*, int);
O409* MaterialProp_Build(O409* o, char* a, int b, char* c, char* d, float f, unsigned char g) {
    S409 s1;
    S409 s2;
    S409 s3;
    o->f0 = 0;
    o->f4 = 0;
    o->f8 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0;
    o->f30 = f;
    o->b34 = g;
    if (a && !String_CompareNoCase(a, "none")) {
        o->fc = -2;
    } else {
        String_CtorCStr_13B480(&s1, a);
        String_AssignString(o, &s1);
        String_Dtor(&s1, 0);
        o->fc = -1;
    }
    if (c && !String_CompareNoCase(c, "none")) {
        o->f10 = -2;
    } else if (!c || !*c) {
        o->f10 = -1;
    } else {
        o->f10 = b;
        String_CtorCStr_13B480(&s2, c);
        String_AssignString(&o->f14, &s2);
        String_Dtor(&s2, 0);
    }
    if (d && !String_CompareNoCase(d, "none")) {
        o->f2c = -2;
    } else {
        String_CtorCStr_13B480(&s3, d);
        String_AssignString(&o->f20, &s3);
        String_Dtor(&s3, 0);
        o->f2c = -1;
    }
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_004095A0 */

/* merge_units: begin func_00409750 */
#pragma push /* merge_units */
Unk409750* MaterialProp_SetDefaults(Unk409750* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk08 = 0;
    self->unk0C = -1;
    self->unk10 = -1;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = -1;
    self->unk30 = 0.2f;
    self->unk34 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00409750 */

/* merge_units: begin func_004097A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_find.h"

/* Find a key in a tree; end() when absent. */
DEFINE_TREE_FIND(func_004097A0, func_0013C310)
#pragma pop /* merge_units */
/* merge_units: end func_004097A0 */

/* merge_units: begin func_00409870 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find a key in a tree; end() when absent. */
DEFINE_TREE_FIND(func_00409870, func_0013C310)
#pragma pop /* merge_units */
/* merge_units: end func_00409870 */

/* merge_units: begin func_00409940 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_obj.h"

extern "C" { char D_004BEBB0[] = "vector::insert length error\n"; }
DEFINE_VECTOR_INSERT_FILL_OBJ(func_00409940, 0x124, 0x542A1, 0x2A150, D_004BEBB0, D_004BEC98, 0x5C, Mem_PlacementNew, func_0040A110, func_0040A070, func_00409E30, func_00409DF0, func_0040A210)
#pragma pop /* merge_units */
/* merge_units: end func_00409940 */
