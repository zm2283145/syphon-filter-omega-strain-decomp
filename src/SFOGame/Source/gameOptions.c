/*
 * SFOGame/Source/gameOptions: 2 files, 00459BA0-00459BD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00459BA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

void* details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_11(char* self) {
    return self + 4;
}

List* std_list_deleter_TextAtom_ctor(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
static inline void merge_flush_func_00459BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00459BA0 */

/* merge_units: begin GuiSubTitleDisplay_459BD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004C1EF0[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_459BD0, 0x1800000, 0xC00000, D_004C1EF0, D_0049AE50, 0x5C, D_0049AF00, 0x64)
static inline void merge_flush_GuiSubTitleDisplay_459BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiSubTitleDisplay_459BD0 */
