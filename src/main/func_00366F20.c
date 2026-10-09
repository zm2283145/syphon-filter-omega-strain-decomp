/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int AnimChannelBase_CopyCtor(L3AnimChannel* self, L3AnimChannel* src);
extern char D_004DA840[];       /* AnimChannel vtable */

/* AnimChannel copy constructor. */
L3AnimChannel* func_00366F20(L3AnimChannel* self, L3AnimChannel* src) {
    AnimChannelBase_CopyCtor(self, src);
    self->vtable = D_004DA840;
    self->wrap = src->wrap;
    return self;
}
