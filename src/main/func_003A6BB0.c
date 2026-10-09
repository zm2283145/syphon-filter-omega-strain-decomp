/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int snd_SendIOPCommandNoWait(int, int, int, int, int);
extern int func_003A7990(int, int, int);
extern int func_0042B5D0(void);
extern int func_0042B770(void);

int func_003A6BB0(void) {
    return func_0042B5D0();
}

int func_003A6BC0(void) {
    return func_0042B770();
}

int func_003A6BD0(void) {
    return func_003A7990(91, 0, 0);
}

void func_003A6BE0(int a0, int a1) {
    int loc[2];
    int a2, v0;

    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 90;
    a1 = 0 + 8;
    v0 = func_003A7990(a0, a1, a2);
    goto ret;
ret:;
}

int func_003A6C10(void) {
    return func_003A7990(64, 0, 0);
}

void func_003A6C20(int a0, int a1, int a2, int a3, int t0) {
    int loc[8];
    int v0;

    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 62;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 20;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    *(int*)((char*)loc + 16) = t0;
    v0 = func_003A7990(a0, a1, a2);
    goto ret;
ret:;
}

int func_003A6C60(void) {
    return func_003A7990(60, 0, 0);
}

int func_003A6C70(void) {
    return func_003A7990(63, 0, 0);
}

int func_003A6C80(void) {
    return func_003A7990(61, 0, 0);
}

void func_003A6C90(int a0, int a1, int a2, int a3, int t0, int t1) {
    int loc[8];
    int v0;

    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 59;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 24;
    *(int*)((char*)loc + 12) = a3;
    a2 = (int)loc;
    *(int*)((char*)loc + 16) = t0;
    *(int*)((char*)loc + 20) = t1;
    v0 = func_003A7990(a0, a1, a2);
    goto ret;
ret:;
}

void func_003A6CD0(int a0, int a1, int a2) {
    int loc[4];
    int a3, t0, v0;

    a3 = 0;
    t0 = 0;
    *(int*)(char*)loc = a0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 15;
    *(int*)((char*)loc + 8) = a2;
    a1 = 0 + 12;
    a2 = (int)loc;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}

void func_003A6D10(int a0, int a1) {
    int loc[2];
    int a2, a3, t0, v0;

    a3 = 0;
    a2 = (int)loc;
    *(int*)(char*)loc = a0;
    t0 = 0;
    *(int*)((char*)loc + 4) = a1;
    a0 = 0 + 14;
    a1 = 0 + 8;
    v0 = snd_SendIOPCommandNoWait(a0, a1, a2, a3, t0);
    goto ret;
ret:;
}
