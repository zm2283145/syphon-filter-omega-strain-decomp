/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: hud.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_list_tCalloutPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
