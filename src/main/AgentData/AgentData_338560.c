/*
 * main/AgentData: 2 files, 00338560-003385A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00338560 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_00338560(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00338560 */

/* merge_units: begin func_003385A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4, (d)->m5 = (s)->m5)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1, (d)->m2 = (s)->m2, (d)->m3 = (s)->m3, (d)->m4 = (s)->m4, (d)->m5 = (s)->m5)

struct E_003385A0 { int m0; int m1; char m2; int m3; int m4; int m5; };
static char D_004B9938[] = "allocator.hh";
DEFINE_VECTOR_INSERT_FILL_CNT(func_003385A0, E_003385A0, 0x400000, 0x200000, D_004B9320, D_004B9938, 0x5C, func_00338B20, void func_0033B590(func_003385A0_V* v, int flags);, func_0033B590(&tmp, -1), VIFC_ASSIGN, VIFC_COPY)
#pragma pop /* merge_units */
/* merge_units: end func_003385A0 */
