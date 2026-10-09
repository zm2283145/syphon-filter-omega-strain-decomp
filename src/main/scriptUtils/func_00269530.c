/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int List_InsertBefore(int, int, int, int);
extern int func_0015C100(int);
extern int func_00269810(int);
extern int func_003D9990(int, int);

int func_00269530(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = List_InsertBefore(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}

int Script_cNodeList_Get(int a0) {
    int loc[1];
    int a1, s0, v0;

    v0 = *(int*)(char*)(a0 + 4);
    *(int*)(char*)loc = v0;
    s0 = *(int*)(char*)loc;
    a0 = *(int*)(char*)a0;
    v0 = func_00269810(a0);
    a0 = *(int*)(char*)(v0 + 96);
    a1 = s0;
    v0 = func_003D9990(a0, a1);
    a0 = v0;
    v0 = func_0015C100(a0);
    goto ret;
ret:
    return v0;
}

int Script_cNodeList_GetSize(int a0) {
    int loc[1];
    int v0;

    a0 = *(int*)(char*)a0;
    v0 = func_00269810(a0);
    v0 = *(int*)(char*)(v0 + 96);
    v0 = *(int*)(char*)(v0 + 4);
    *(int*)(char*)loc = v0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}
