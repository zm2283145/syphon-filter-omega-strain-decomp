/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DAE50[];
extern char D_004DCF10[];
extern char D_004F5410[];
extern int Event_Construct(int, int);

int func_00210170(int a0, int a1) {
    Event_Construct(a0, (int)D_004F5410);
    *(int*)((char*)a0) = (int)D_004DCF10;
    *(int*)((char*)a0) = (int)D_004DAE50;
    *(char*)((char*)a0 + 36) = a1;
    return a0;
}
