/*
 * main/GuiAgentInfo: range (3 files, 00362940-003629B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00362940 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


int func_00362940(char* self) {
    return *(int*)(self + 0);
}

void func_00362950(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

void func_00362970(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* func_00362980(char* self) {
    return self + 180;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362940 */

/* merge_units: begin func_00362990 */
#pragma push /* merge_units */
typedef struct { char pad[0xB8]; int v; } ObjB8;
/* Returns whether the field at +0xB8 is set. */
int func_00362990(ObjB8* o) { return !(o->v == 0); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00362990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00362990 */

/* merge_units: begin func_003629B0 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; } QPair;

#pragma peephole off
/* Copies a pair of quadwords and returns the destination (unit built with the peephole pass off). */
QPair* func_003629B0(QPair* dst, QPair* src)
{
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
#pragma peephole reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003629B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003629B0 */
