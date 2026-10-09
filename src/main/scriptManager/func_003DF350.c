/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

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
