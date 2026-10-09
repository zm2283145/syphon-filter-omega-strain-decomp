/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00131440(int, int);
extern int List_InsertBefore(int, int, int, int);
extern int func_002426D0(int);

int func_001313D0(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    a1 = a0;
    v0 = *(int*)(char*)(a0 + 8);
    a2 = (int)loc;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    v0 = List_InsertBefore(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}

int World_RegisterActor(int a0, int a1) {
    int v0;

    *(int*)(char*)(a0 + 188) = a1;
    v0 = *(int*)(char*)(a1 + 48);
    a0 = v0 + 12;
    v0 = func_002426D0(a0);
    goto ret;
ret:
    return v0;
}

void World_RegisterNode(int a0, int a1) {
    int loc[1];
    int v0;

    a0 = a0 + 156;
    *(int*)(char*)loc = a1;
    a1 = (int)loc;
    v0 = func_00131440(a0, a1);
    goto ret;
ret:;
}

int func_00131440(int a0, int a1) {
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
