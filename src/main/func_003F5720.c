/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004BE1B0[];
extern char D_0055C4C8[];
extern int func_00127358(int, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern int func_003F4B40(int);
extern int func_003F4EF0(int);
extern int func_003F5050(int);
extern void func_003F7FF0(void);

int func_003F5720(void) {
    func_003F4B40((int)D_0055C4C8);
    return 1;
}

int func_003F5750(void) {
    func_003F4EF0((int)D_0055C4C8);
    return 1;
}

int func_003F5780(void) {
    func_003F7FF0();
    func_003F5050((int)D_0055C4C8);
    return 1;
}

int func_003F57B0(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f12, float f13, float f14, float f15, float f16, float f17, float f18, float f19) {
    int tmp0;

    tmp0 = *(int*)((char*)a1 + 4);
    func_00127358((int)D_004BE1B0, tmp0, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    return 1;
}
