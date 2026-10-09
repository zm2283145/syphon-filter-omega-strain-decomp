/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_001F2CA0(int, int);
extern int func_001F2D20(int);
extern int func_001F4070(int);
extern void func_001F40B0(void);

int func_001F4030(int a0, int a1) {
    return func_001F2CA0(a0, a1);
}

int func_001F4040(int a0) {
    func_001F4070(a0);
    return a0;
}

int func_001F4070(int a0) {
    func_001F2D20(a0);
    return a0;
}

void func_001F40A0(void) {
    func_001F40B0();
}
