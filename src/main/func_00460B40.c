/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFC04[];
extern int func_00139200(int, int, int, int);
extern int func_002C9E20(int);
extern int func_0041F090(int);

int* func_00460B40(PtrVec* v, int i) {
    return v->data + i;
}

int func_00460B50(char* self) {
    return *(int*)(self + 4);
}

int func_00460B60(int a0, int a1) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 4);
    tmp1 = *(int*)((char*)a0 + 8);
    return func_00139200(a0, (tmp1 + (tmp0 << 2)), 1, a1);
}

int func_00460B80(int a0) {
    int tmp2;
    int tmp3;

    func_0041F090(a0);
    tmp2 = *(int*)D_004FFC04;
    tmp3 = func_002C9E20(tmp2);
    return tmp3;
}
