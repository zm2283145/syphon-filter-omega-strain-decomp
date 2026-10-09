/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int ScriptStr_AppendTracking(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

void func_003E03F0(ScriptManager* self, int value) {
    self->unk4E68 = value;
}
