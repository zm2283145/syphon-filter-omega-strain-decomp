/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0038E100(int);
extern void func_003A9F00(int);
extern int func_003A9F10(int);
extern void func_003CE790(int);
extern void func_003CE7D0(int);
extern void func_003CE810(int);

void func_003928A0(int a0) {
    func_003CE7D0(a0);
    func_003A9F00((a0 + 11856));
}

void func_003928D0(int a0) {
    func_003CE790(a0);
    func_003A9F00((a0 + 11856));
}

void func_00392900(int a0) {
    func_003A9F10((a0 + 11856));
    *(int*)((char*)a0 + 11364) = (a0 + 11856);
    func_0038E100((a0 + 96));
    func_003CE810(a0);
}
