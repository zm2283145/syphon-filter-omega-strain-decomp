/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_0010A6E0(int, int, int, int, int);
extern int func_003F5350(int, int);
extern int func_003F53B0(int, int, int, int, int);

int func_003F5D40(int a0, int a1) {
    return func_003F5350((a0 + 72), a1);
}

int func_003F5D50(int a0, int a1, int a2, int a3, int t0) {
    return func_003F53B0((a0 + 72), a1, a2, a3, t0);
}

int func_003F5D60(int a0, int a1, int a2, int a3, int t0) {
    func_0010A6E0(a0, (a1 & 255), a2, a3, t0);
    return 1;
}
