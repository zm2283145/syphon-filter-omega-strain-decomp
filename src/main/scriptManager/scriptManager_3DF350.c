/*
 * main/scriptManager: range (2 files, 003DF350-003DF3D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptManager_types.h"

/* merge_units: begin func_003DF350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);
extern OwnedVec* func_003DF3D0(OwnedVec* v);

int* func_003DF350(PtrVec* v, int i) {
    return v->data + i;
}

int* Script_GetStringTableEntry(PtrVec* v, int i) {
    return v->data + i;
}

int* func_003DF370(PtrVec* v, int i) {
    return v->data + i;
}

/* push_back: inserts one value at the end. */
int func_003DF380(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

OwnedVec* func_003DF3A0(OwnedVec* v) {
    func_003DF3D0(v);
    v->unk0C = 1;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DF350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DF350 */

/* merge_units: begin func_003DF3D0 */
#pragma push /* merge_units */
/* Clears the three PtrVec words. */
OwnedVec* func_003DF3D0(OwnedVec* v) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    return v;
}

int* func_003DF3F0(PtrVec* v, int i) {
    return v->data + i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DF3D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DF3D0 */
