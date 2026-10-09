/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

extern void func_003D9470(OwnedVec* v, int a1, int a2);

/* Clears the three PtrVec words, then calls func_003D9470 with the remaining arguments. */
OwnedVec* func_003D9240(OwnedVec* v, int a1, int a2) {
    v->unk0 = 0;
    v->count = 0;
    v->data = 0;
    func_003D9470(v, a1, a2);
    return v;
}
