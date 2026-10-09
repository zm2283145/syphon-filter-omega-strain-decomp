/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D9960[];
extern char D_004EE6C0[];
extern int func_00139070(int);
extern int func_003CB4B0(int, int);

int func_001716E0(int a0, int a1) {
    func_003CB4B0(a0, (int)D_004EE6C0);
    *(int*)((char*)a0) = (int)D_004D9960;
    func_00139070((a0 + 40));
    *(int*)((char*)a0 + 32) = a1;
    *(int*)((char*)a0 + 36) = 0;
    return a0;
}
