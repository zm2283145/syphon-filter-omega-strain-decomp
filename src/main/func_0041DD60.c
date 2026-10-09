/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int List_InsertBefore(int, int, int, int);
extern int func_002CCE50(int, int);

int func_0041DD60(int a0, int a1) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a1;
    v0 = *(int*)(char*)loc;
    a1 = (int)loc;
    *(int*)(char*)(v0 + 28) = a0;
    a0 = a0 + 40;
    v0 = func_002CCE50(a0, a1);
    goto ret;
ret:
    return v0;
}

int func_0041DD90(int a0, int a1) {
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
