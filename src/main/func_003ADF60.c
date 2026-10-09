/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

float func_003ADF60(FStack* s) {
    float* p = &s->vals[s->count - 1];
    return *p;
}
