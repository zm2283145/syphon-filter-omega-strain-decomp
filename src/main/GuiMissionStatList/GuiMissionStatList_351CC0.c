/*
 * main/GuiMissionStatList: 2 files, 00351CC0-00351D00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00351CC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_37(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_00351CC0 */

/* merge_units: begin func_00351D00 */
#pragma push /* merge_units */
typedef struct Words15D00 { int w[15]; } Words15D00;
typedef struct Elem5CD00 {
    char base[0xC];
    unsigned char flag;
    char pad0D[3];
    Words15D00 data;
    char tail[0x10];
} Elem5CD00;

extern void cString_opAssign(Elem5CD00* dst, Elem5CD00* src);
extern void cArray_StatsRequirement_opAssign(void* dst, void* src);

/* Fills n elements starting at dest with copies of value. */
void std_fill_n_MissionStats_int_fill_n(Elem5CD00* dest, int n, Elem5CD00* value) {
    for (; n != 0; --n, ++dest) {
        cString_opAssign(dest, value);
        dest->flag = value->flag;
        dest->data = value->data;
        cArray_StatsRequirement_opAssign(dest->tail, value->tail);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00351D00 */
