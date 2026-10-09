/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_0048A158[];
extern char D_0048A160[];
extern char D_004DA3E0[];
extern int PhysicalBase_Construct(int, int, int);

int func_0017F2E0(int a0) {
    PhysicalBase_Construct(a0, (int)D_0048A158, (int)D_0048A160);
    *(int*)((char*)a0) = (int)D_004DA3E0;
    *(int*)((char*)a0 + 56) = 0;
    *(int*)((char*)a0 + 60) = 0;
    return a0;
}
