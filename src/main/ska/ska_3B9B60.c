/*
 * main/ska: range (3 files, 003B9B60-003B9BD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003B9B60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


List* std_list_deleter_voidPtr_ctor_cAllocatorR(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B9B60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B9B60 */

/* merge_units: begin func_003B9B80 */
#pragma push /* merge_units */
typedef struct Quad4 {
    int a, b, c, d;
} Quad4;

/* Swaps two 16-byte records word by word. */
void _cdeque_deleter_common_int_swap(Quad4* x, Quad4* y) {
    int t;
    if (x == y) return;
    t = x->a; x->a = y->a; y->a = t;
    t = x->b; x->b = y->b; y->b = t;
    t = x->c; x->c = y->c; y->c = t;
    t = x->d; x->d = y->d; y->d = t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B9B80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B9B80 */

/* merge_units: begin func_003B9BD0 */
#pragma push /* merge_units */
unsigned int D_004BCEE8[2] = { 0x0, 0x0 };
extern signed char D_00542C90;

/* Lazily initialised constant: 0x1800000 - 1 (guarded function-local static). */
int _cdeque_deleter_common_int_max_size(void) {
    int size[1];
    int ref;

    if (D_00542C90 == 0) {
        ref = (int)size; /* value is read back through its address (inlined helper) */
        size[0] = 0x1800000;
        ref = *(int*)ref;
        D_00542C90 = 1;
        (*(int*)D_004BCEE8) = ref - 1;
    }
    return (*(int*)D_004BCEE8);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B9BD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B9BD0 */
