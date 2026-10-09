/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Loader_InitNIEventLights(int, int);
extern int Loader_InitNIEventObjects(int, int, int);

int func_001C3050(int a0, int a1, int a2) {
    int tmp2;

    Loader_InitNIEventLights(a0, a1);
    tmp2 = Loader_InitNIEventObjects(a0, a1, a2);
    return tmp2;
}
