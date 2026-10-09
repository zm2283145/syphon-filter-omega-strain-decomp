/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern AnimChannel* AnimChannelBase_CopyCtor(AnimChannel* self, AnimChannel* src);
extern char D_004DA840[];   /* AnimChannel vtable */

/* AnimChannel copy constructor (inline copy emitted in this unit). */
AnimChannel* AnimChannel_CopyCtor_291D00(AnimChannel* self, AnimChannel* src) {
    AnimChannelBase_CopyCtor(self, src);
    self->base.vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
