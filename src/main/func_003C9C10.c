/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005435C0[];

int func_003C9C10(void) {
    int tmp0;

    tmp0 = *(int*)D_005435C0;
    return tmp0;
}

int func_003C9C20(char* self) {
    return *(int*)(self + 4);
}
