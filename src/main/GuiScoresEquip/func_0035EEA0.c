/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiScoresEquip.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "GuiScoresEquip_types.h"

extern AnimChannel* AnimChannelBase_CopyCtor(AnimChannel* self, AnimChannel* src);
extern char D_004DA840[];   /* AnimChannel vtable */

/* AnimChannel copy constructor (inline copy emitted in this unit). */
AnimChannel* AnimChannel_CopyCtor_35EEA0(AnimChannel* self, AnimChannel* src) {
    AnimChannelBase_CopyCtor(self, src);
    self->base.vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
