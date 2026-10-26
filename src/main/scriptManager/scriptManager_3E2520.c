/*
 * main/scriptManager: range (2 files, 003E2520-003E25C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003E2520 */
#pragma push /* merge_units */
typedef struct { int n; int a[5000]; } FA_003E2520;
extern int D_004938E0;
static inline void fill_003E2520(FA_003E2520 *s, int n, int *v) {
    int i;
    for (i = s->n; i <= (int)(n - 1); i++) *(int *)((char *)s->a + (i << 2)) = *v;
    s->n = n;
}
void cArray_FixedCapacity_int_5000_ResizeActual(FA_003E2520 *s, unsigned int n, int *v) {
    if (n < 5001U) {
        fill_003E2520(s, n, v);
        return;
    }
    fill_003E2520(s, 5000, &D_004938E0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E2520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E2520 */

/* merge_units: begin func_003E25C0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } T25C0;
extern void std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_2(T25C0* t, void* n);
extern void operator_delete(void* p);
T25C0* cAssocArray_int_cArray_FuncDefPtrPtr_dtor(T25C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP_2(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E25C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E25C0 */
