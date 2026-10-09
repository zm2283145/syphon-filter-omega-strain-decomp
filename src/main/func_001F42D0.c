/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0016E880(int, int);
extern int func_001F4260(int, int);
extern void func_001F4320(void);

void func_001F42D0(int a0) {
    int loc[1];
    int a1, s0, v0;

    s0 = a0;
    a0 = (int)loc;
    func_0016E880(a0, a1);
    a1 = *(int*)(char*)loc;
    a0 = s0;
    v0 = func_001F4260(a0, a1);
    goto ret;
ret:;
}

void func_001F4310(void) {
    func_001F4320();
}
