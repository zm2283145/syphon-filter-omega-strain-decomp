/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_003FDB80(int);
extern int func_003FE650(int);

int func_003FDB40(int a0) {
    return func_003FE650(a0);
}

int func_003FDB50(int a0) {
    int tmp0;
    int tmp2;

    tmp0 = func_003FE650(a0);
    tmp2 = func_003FDB80(tmp0);
    return tmp2;
}
