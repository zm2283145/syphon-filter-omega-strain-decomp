/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00572470[];
extern char D_00572478[];
extern int func_0042A870(int);

int func_0042A960(int a0) {
    *(int*)D_00572470 = 0;
    *(int*)D_00572478 = 1;
    return func_0042A870(a0);
}
