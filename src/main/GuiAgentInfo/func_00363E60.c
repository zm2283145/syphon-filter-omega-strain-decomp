/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiAgentInfo_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back on a pointer vector. */
int func_00363E60(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
