/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004DED50[];
extern int func_00356FF0(int);

int func_0034E7F0(int a0) {
    func_00356FF0(a0);
    *(int*)((char*)a0) = (int)D_004DED50;
    *(int*)((char*)a0 + 100) = 6;
    return a0;
}
