/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* begin(): iterator at the first element. */
void func_003C9340(Iter* out, PtrVec* v) {
    out->p = v->data;
}
