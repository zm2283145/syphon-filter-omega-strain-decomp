/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(int, int, int, int);
extern int func_003DF3D0(int);

int* func_003DF350(PtrVec* v, int i) {
    return v->data + i;
}

int* Script_GetStringTableEntry(PtrVec* v, int i) {
    return v->data + i;
}

int* func_003DF370(PtrVec* v, int i) {
    return v->data + i;
}

int func_003DF380(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}

int func_003DF3A0(int a0) {
    func_003DF3D0(a0);
    *(char*)((char*)a0 + 12) = 1;
    return a0;
}
