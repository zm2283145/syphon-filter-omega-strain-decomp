/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_001F3010(void);
extern void func_0020C840(int);

void func_001F2FF0(int a0) {
    func_0020C840(a0);
}

void func_001F3000(void) {
    func_001F3010();
}
