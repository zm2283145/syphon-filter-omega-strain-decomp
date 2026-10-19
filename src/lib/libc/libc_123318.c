/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00489738[];

void func_00123318(void) {

}

int Newlib_Errno(void) {
    int tmp0;

    tmp0 = *(int*)D_00489738;
    return tmp0;
}
