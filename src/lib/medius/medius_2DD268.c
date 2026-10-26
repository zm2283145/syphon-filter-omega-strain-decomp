/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int D_0048C480 = 0;
int D_0048C484 = 0;

int NetSetPeerToPeerHostChangeCallback(int a0, int a1) {
    *(int*)((char*)&D_0048C480) = a0;
    *(int*)((char*)&D_0048C484) = a1;
    return 0;
}
