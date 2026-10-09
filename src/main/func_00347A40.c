/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DEB10[];
extern int func_0033D580(int);

int func_00347A40(int a0) {
    func_0033D580(a0);
    *(int*)((char*)a0) = (int)D_004DEB10;
    *(int*)((char*)a0 + 132) = 9;
    *(int*)((char*)a0 + 136) = 0;
    *(int*)((char*)a0 + 156) = -1;
    return a0;
}
