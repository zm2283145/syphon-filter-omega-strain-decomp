/*
 * main/GuiGameScreen: 3 files, 00461D80-00461EB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00461D80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_52(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00461D80 */

/* merge_units: begin func_00461DC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00461DC0, func_00461FA0, D_004C2568)
#pragma pop /* merge_units */
/* merge_units: end func_00461DC0 */

/* merge_units: begin func_00461EB0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(std_vector_deleter_tQuip_dtor, std_vector_deleter_tAchievementInfo_clear, D_004AA5B8)
#pragma pop /* merge_units */
/* merge_units: end func_00461EB0 */
