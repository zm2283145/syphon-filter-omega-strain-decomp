/*
 * main/path: range (2 files, 00163F60-00163F90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "path_types.h"

/* merge_units: begin func_00163F60 */
#pragma push /* merge_units */
typedef struct { int unk0; int items[1]; } Arr4;
static inline Iter Iter_Make(int* p) { Iter it; it.p = p; return it; }
/* Stores an iterator to the first element (at +4) into out. */
void std_list_cPathSystemRequestPtr_end_void_2(Iter* out, Arr4* a) { Iter it = Iter_Make(a->items); out->p = it.p; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163F60 */

/* merge_units: begin func_00163F90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Word copy.
 */


Word* cConstLListIterator_cPathSystemRequestPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00163F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00163F90 */
