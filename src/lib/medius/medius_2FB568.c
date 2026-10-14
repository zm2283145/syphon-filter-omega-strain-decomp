/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004908E0[];
extern char D_004908E4[];

int func_002FB568(int a0, int a1) {
    *(int*)D_004908E0 = a0;
    *(int*)D_004908E4 = a1;
    return 0;
}
