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
CurveBinding* Curve_Bind(CurveBinding* b, int curve) {
    b->curve = curve;
    b->unk4 = 0;
    return b;
}
