/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003361E0(int);

int func_003361B0(int a0) {
    int tmp0;

    tmp0 = func_003361E0(a0);
    *(char*)((char*)a0 + 2220) = 0;
    *(char*)((char*)a0 + 2236) = 0;
    *(char*)((char*)a0 + 2252) = 0;
    return tmp0;
}
