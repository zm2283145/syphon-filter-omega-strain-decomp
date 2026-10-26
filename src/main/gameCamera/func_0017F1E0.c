/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

typedef struct Binding {
    int target;
    int unk4;
} Binding;

/* Initializes the binding with target and clears the second word. */
Binding* cSplineWithScaledDuration_Iterator_cHermiteSplineWithScaledDuration_cVector_cVector_ctor(Binding* b, int target) {
    b->target = target;
    b->unk4 = 0;
    return b;
}
