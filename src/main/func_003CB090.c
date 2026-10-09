/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DFDA0[];
extern char D_004DFDE0[];
extern char D_00543640[];
extern char D_00543650[];
extern char D_00555070[];
extern int ScalarCollection_Init(int);
extern int ScriptFilter_Dispatch(int, int, int);

int func_003CB090(int a0, int a1) {
    int tmp0;

    *(int*)((char*)a0) = (int)D_004DFDE0;
    *(int*)((char*)a0 + 4) = 0xbebaafde;
    *(int*)((char*)a0 + 8) = (int)D_00543650;
    tmp0 = *(int*)(char*)a1;
    *(int*)((char*)a0 + 12) = tmp0;
    *(int*)((char*)a0 + 16) = -1;
    *(char*)((char*)a0 + 20) = 1;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0) = (int)D_004DFDA0;
    ScalarCollection_Init((a0 + 32));
    return a0;
}

int func_003CB110(int a0) {
    *(int*)((char*)a0) = (int)D_004DFDE0;
    *(int*)((char*)a0 + 4) = 0xbebaafde;
    *(int*)((char*)a0 + 8) = (int)D_00543650;
    *(int*)((char*)a0 + 12) = -1;
    *(int*)((char*)a0 + 16) = -1;
    *(char*)((char*)a0 + 20) = 1;
    *(int*)((char*)a0 + 24) = 0;
    *(int*)((char*)a0) = (int)D_004DFDA0;
    ScalarCollection_Init((a0 + 32));
    return a0;
}

void func_003CB190(void) {
}

int func_003CB1A0(int a0) {
    int loc[1];
    int v0;

    *(int*)(char*)loc = a0;
    v0 = *(int*)(char*)loc;
    goto ret;
ret:
    return v0;
}

void* func_003CB1C0(void* self) {
    return self;
}

int func_003CB1D0(void) {
    return (int)D_00543640;
}

int func_003CB1E0(void) {
    int tmp0;

    tmp0 = *(int*)D_00543640;
    return tmp0;
}

int func_003CB1F0(int a0, int a1) {
    return ScriptFilter_Dispatch((int)D_00555070, a0, a1);
}

int Receiver_HandleEventBase(void) {
    return 0;
}

int func_003CB220(char* self) {
    return *(int*)(self + 8);
}
