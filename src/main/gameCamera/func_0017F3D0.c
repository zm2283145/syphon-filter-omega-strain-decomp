/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

typedef struct CurveBinding {
    int curve;
    int unk4;
} CurveBinding;

/* Binds a curve and clears the second word. */
CurveBinding* cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_float_float_ctor(CurveBinding* b, int curve) {
    b->curve = curve;
    b->unk4 = 0;
    return b;
}
