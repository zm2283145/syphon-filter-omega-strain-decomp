/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003DFFE0(int);
extern void ScriptStack_Push(int, int);

float func_003DFFB0(void) {
    int loc[1];
    int a0, v0;
    float f0;

    v0 = func_003DFFE0(a0);
    *(int*)(char*)loc = v0;
    f0 = *(float*)(char*)loc;
    goto ret;
ret:
    return f0;
}

int func_003DFFE0(int a0) {
    int tmp0;
    int tmp1;

    tmp0 = *(int*)((char*)a0 + 20080);
    *(int*)((char*)a0 + 20080) = (tmp0 + 4);
    tmp1 = *(int*)(char*)tmp0;
    return tmp1;
}

void func_003E0000(float f12) {
    int loc[1];
    int a0, a1;

    *(float*)(char*)loc = f12;
    a1 = *(int*)(char*)loc;
    ScriptStack_Push(a0, a1);
    goto ret;
ret:;
}

void ScriptStack_Push(int a0, int a1) {
    *(int*)((char*)a0 + 20080) = (*(int*)((char*)a0 + 20080) + -4);
    *(int*)((char*)*(int*)((char*)a0 + 20080)) = a1;
}
