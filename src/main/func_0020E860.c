/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004D97F0[];
extern char D_004F53E8[];
extern int Event_Construct(int, int);

int func_0020E860(int a0, int a1) {
    Event_Construct(a0, (int)D_004F53E8);
    *(int*)((char*)a0) = (int)D_004D97F0;
    *(char*)((char*)a0 + 36) = a1;
    return a0;
}
