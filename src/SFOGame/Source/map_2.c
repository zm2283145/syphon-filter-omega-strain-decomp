/*
 * SFOGame/Source/map: 2 files, 0026C320-0026C350
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026C320 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int unk0; int items[1]; } Arr4;
static inline Iter Iter_Make(int* p) { Iter it; it.p = p; return it; }
/* Stores an iterator to the first element (at +4) into out. */
void std_list_cHudTargetInfoPtr_end_void(Iter* out, Arr4* a) { Iter it = Iter_Make(a->items); out->p = it.p; }
static inline void merge_flush_func_0026C320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C320 */

/* merge_units: begin func_0026C350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* cConstLListIterator_cHudTargetInfoPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0026C350(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C350 */
