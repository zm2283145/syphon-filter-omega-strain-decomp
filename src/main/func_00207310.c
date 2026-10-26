/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int String_CopyCtor(int, int);

int cString_ctor_cStringR(int a0, int a1) {
    String_CopyCtor(a0, a1);
    return a0;
}
