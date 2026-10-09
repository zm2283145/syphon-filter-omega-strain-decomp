/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int Transport_Send(int, int, int, int);

int func_00428FD0(int a0, int a1) {
    return Transport_Send(a1, a0, -1, -1);
}
