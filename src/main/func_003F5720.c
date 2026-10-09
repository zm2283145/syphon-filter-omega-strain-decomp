/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004BE1B0[];
extern char D_0055C4C8[];
extern int func_00127358(void*, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern int func_003F4B40(void*);
extern int func_003F4EF0(void*);
extern int func_003F5050(void*);
extern void func_003F7FF0(void);

int func_003F5720(void) {
    func_003F4B40(D_0055C4C8);
    return 1;
}

int func_003F5750(void) {
    func_003F4EF0(D_0055C4C8);
    return 1;
}

int func_003F5780(void) {
    func_003F7FF0();
    func_003F5050(D_0055C4C8);
    return 1;
}

/* Forwards its arguments to func_00127358, replacing the first two with D_004BE1B0 and the second word of *a1. */
int func_003F57B0(int a0, int* a1, int a2, int a3, int a4, int a5, int a6, int a7, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7) {
    func_00127358(D_004BE1B0, a1[1], a2, a3, a4, a5, a6, a7, f0, f1, f2, f3, f4, f5, f6, f7);
    return 1;
}
