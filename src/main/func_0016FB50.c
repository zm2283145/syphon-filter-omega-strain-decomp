/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int Script_cHotbox_Occupied(int a0) {
    return (0 < *(int*)((char*)*(int*)(char*)a0 + 152));
}

int Script_cHotbox_ClearInteractMessage(int a0) {
    int v0, v1;

    v1 = *(int*)(char*)a0;
    v0 = 0;
    *(int*)(char*)(v1 + 160) = 0;
    goto ret;
ret:
    return v0;
}
