/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00504080[];
extern char D_005040C0[];
extern int func_00110528(int, int, int, int, int, int, int, int);
extern int func_0027C3D0(void);
extern void func_0027D278(int);

int func_0027C4D8(void) {
    int loc[4];
    int a0, a1, a2, a3, t0, t1, t2, t3, v0, v1;

    func_0027D278(a0);
    v0 = func_0027C3D0();
    a3 = (int)D_005040C0;
    a0 = (int)D_00504080;
    *(int*)(char*)loc = 0;
    a1 = 0 + 15;
    a2 = 0;
    t0 = 0 + 4096;
    t1 = a3;
    t2 = 0 + 4096;
    t3 = 0;
    v0 = func_00110528(a0, a1, a2, a3, t0, t1, t2, t3);
    v1 = 0 + -1;
    v1 = v1 < v0;
    if (v1 != 0) v0 = 0;
    goto ret;
ret:
    return v0;
}
