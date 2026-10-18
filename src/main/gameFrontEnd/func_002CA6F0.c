/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00532FE8;
extern int App_Broadcast(int, int, int);

int func_002CA6F0(void) {
    D_00532FE8 = 1;
    return App_Broadcast(8192, 0, 0);
}
