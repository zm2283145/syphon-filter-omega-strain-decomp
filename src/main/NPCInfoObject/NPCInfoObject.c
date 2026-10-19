/*
 * main/NPCInfoObject: 2 files, 00432F20-00432F50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00432F20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "types.h"

Word* func_00432F20(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_00432F30(Iter* out, Tree* t) {
    out->p = &t->header;
}

void func_00432F40(Iter* out, Tree* t) {
    out->p = t->leftmost;
}
#pragma pop /* merge_units */
/* merge_units: end func_00432F20 */

/* merge_units: begin func_00432F50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
#include "npc_info_rec.h"
}
#include "npc_info_purge.h"
DEFINE_NPC_INFO_PURGE(func_00432F50, D_00582AB0, 1, 0x683)
#pragma pop /* merge_units */
/* merge_units: end func_00432F50 */
