/*
 * main/path: range (2 files, 0015DD80-0015DDB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0015DD80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* std_vector_int_opIndex_uint(PtrVec* v, int i) {
    return v->data + i;
}

Rel* std_vector_cBox_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015DD80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015DD80 */

/* merge_units: begin func_0015DDB0 */
#pragma push /* merge_units */
typedef struct PtrTable {
    int unk0;
    int unk4;
    void** items;
} PtrTable;

extern PtrTable* D_004FFBE0;
extern int D_004EE130;

/* Returns table item i, or &D_004EE130 when no table exists. */
void* NpcPath_GetNode(int i) {
    if (D_004FFBE0 != 0) return D_004FFBE0->items[i];
    return &D_004EE130;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015DDB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015DDB0 */
