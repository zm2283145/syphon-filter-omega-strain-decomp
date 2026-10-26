/*
 * main/AgentData: 2 files, 00337F50-00337F90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00337F50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_29(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00337F50 */

/* merge_units: begin func_00337F90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4, (d)->m5 = (s)->m5, (d)->m6 = (s)->m6)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4, (d)->m5 = (s)->m5, (d)->m6 = (s)->m6)

struct E_00337F90 { int m0; int m1; char m2; int m3; int m4; int m5; int m6; };
static char D_004B9948[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CNT(std_vector_imp_tRequirementInfo_insert, E_00337F90, 0x36DB6D, 0x1B6DB6, D_004B9320, D_004B9948, 0x5C, std_swap_vectordeleterR_vectordeleterR_30, void std_vector_deleter_tRequirementInfo_dtor(std_vector_imp_tRequirementInfo_insert_V* v, int flags);, std_vector_deleter_tRequirementInfo_dtor(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
#pragma pop /* merge_units */
/* merge_units: end func_00337F90 */
