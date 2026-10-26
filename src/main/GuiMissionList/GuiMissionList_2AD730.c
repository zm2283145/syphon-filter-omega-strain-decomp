/*
 * main/GuiMissionList: 3 files, 002AD730-002AD870
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002AD730 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_25(PtrVec* a, PtrVec* b) {
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

/* Vector clear (count = 0). */
void std_vector_deleter_SelectElem_clear(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002AD730 */

/* merge_units: begin func_002AD780 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "clear_buffer_dtor.h"

/* Clear and free a vector, optionally delete. */
DEFINE_CLEAR_BUFFER_DTOR(std_vector_deleter_SelectElem_dtor_void_2, D_004ABA60)
#pragma pop /* merge_units */
/* merge_units: end func_002AD780 */

/* merge_units: begin func_002AD870 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004ABA50[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(GuiMissionList_Create, 0x124, D_004ABA50, GuiMissionList_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_002AD870 */
