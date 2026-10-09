/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DEDE0[];
extern int func_00356FF0(int);

int func_0034F070(int a0) {
    func_00356FF0(a0);
    *(int*)((char*)a0) = (int)D_004DEDE0;
    *(int*)((char*)a0 + 100) = 8;
    return a0;
}
