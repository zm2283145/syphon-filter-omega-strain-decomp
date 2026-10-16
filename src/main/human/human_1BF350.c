/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int AnimChannelBase_CopyCtor(CurveChannel* d, CurveChannel* s);
extern char D_004DA840[]; /* AnimChannel vtable */

/* Copy constructor (research ANIMATION_CHANNEL_NATIVE.md). */
AnimChannel* AnimChannel_CopyCtor(AnimChannel* d, AnimChannel* s) {
    unsigned char wrap;

    AnimChannelBase_CopyCtor(&d->base, &s->base);
    d->base.vtable = D_004DA840;
    wrap = s->wrap;
    d->wrap = wrap;
    return d;
}
