/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Clears the word at +4 (the count when used as a PtrVec). */
void func_002CE740(PtrVec* v) {
    v->count = 0;
}
