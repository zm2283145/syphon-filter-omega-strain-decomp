/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DBA20[];
extern int func_003EA630(int);

int func_00230240(int a0) {
    func_003EA630(a0);
    *(int*)((char*)a0) = (int)D_004DBA20;
    *(int*)((char*)a0 + 56) = 1065353216;
    *(int*)((char*)a0 + 60) = -1;
    *(int*)((char*)a0 + 64) = 0;
    return a0;
}
