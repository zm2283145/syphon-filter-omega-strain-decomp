/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00533760[];
extern int func_0035B390(int);

int func_0035DF30(void) {
    int tmp0;

    tmp0 = *(int*)D_00533760;
    return func_0035B390(tmp0);
}
