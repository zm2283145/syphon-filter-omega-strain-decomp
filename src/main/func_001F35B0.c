/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0013D890(int, int);
extern int func_001F2ED0(int, int);
extern int func_001F3620(int, int);

int func_001F35B0(int a0, int a1) {
    func_001F2ED0(a0, a1);
    return a0;
}

void func_001F35E0(int a0) {
    int loc[1];
    int a1, s0, v0;

    s0 = a0;
    a0 = (int)loc;
    func_0013D890(a0, a1);
    a1 = *(int*)(char*)loc;
    a0 = s0;
    v0 = func_001F3620(a0, a1);
    goto ret;
ret:;
}

int func_001F3620(int a0, int a1) {
    int loc[1];
    int s0, v0;

    *(int*)(char*)loc = a1;
    s0 = a0;
    a1 = (int)loc;
    v0 = func_001F2ED0(a0, a1);
    v0 = s0;
    goto ret;
ret:
    return v0;
}
