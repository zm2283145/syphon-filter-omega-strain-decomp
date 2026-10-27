/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int cSplinedMotion_float_ctor_cSplinedMotionR(CurveChannel* d, CurveChannel* s);
extern char D_004DA840[]; /* AnimChannel vtable */

/* Copy constructor (research ANIMATION_CHANNEL_NATIVE.md). */
AnimChannel* cSkaSliderValue_ctor_cSkaSliderValueR(AnimChannel* d, AnimChannel* s) {
    unsigned char wrap;

    cSplinedMotion_float_ctor_cSplinedMotionR(&d->base, &s->base);
    d->base.vtable = D_004DA840;
    wrap = s->wrap;
    d->wrap = wrap;
    return d;
}
