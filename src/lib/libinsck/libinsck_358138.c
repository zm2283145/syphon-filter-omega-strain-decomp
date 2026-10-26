/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_005335D8[];
extern char D_005335DC[];

int sceInsockSetMallocFunction(int a0) {
    int tmp0;

    tmp0 = *(int*)D_005335D8;
    *(int*)D_005335D8 = a0;
    return tmp0;
}

int sceInsockSetFreeFunction(int a0) {
    int tmp0;

    tmp0 = *(int*)D_005335DC;
    *(int*)D_005335DC = a0;
    return tmp0;
}
