/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Insert(int, int, int, int);
extern int PtrVector_Resize(int, int, int);
extern int func_001396D0(int, int);

int func_0040BC50(int a0, int a1, int a2) {
    return PtrVector_Resize(a0, a1, a2);
}

int func_0040BC60(char* self) {
    return *(int*)(self + 4);
}

int func_0040BC70(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return PtrVec_Insert(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}

int func_0040BC90(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_0040BCA0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
