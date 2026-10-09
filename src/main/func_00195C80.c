/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004E0840[];
extern char D_0055D480[];
extern int func_003C9E30(int, int);

int func_00195C80(int a0, int a1, int a2) {
    func_003C9E30(a0, (int)D_0055D480);
    *(int*)((char*)a0) = (int)D_004E0840;
    *(int*)((char*)a0 + 36) = a1;
    *(char*)((char*)a0 + 40) = a2;
    return a0;
}
