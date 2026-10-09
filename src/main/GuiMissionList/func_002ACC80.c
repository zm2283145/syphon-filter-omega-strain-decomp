/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_002ACB70(int);

int func_002ACC80(int a0, int a1) {
    *(int*)((char*)a0 + 284) = a1;
    *(int*)((char*)a0 + 204) = -1;
    *(int*)((char*)a0 + 196) = -1;
    *(int*)((char*)a0 + 192) = -1;
    return func_002ACB70(a0);
}
