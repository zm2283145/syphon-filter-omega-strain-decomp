/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DAE50;
extern void* D_004DCF10;
extern char D_004F5410[];
extern ByteEvent* Event_Construct(ByteEvent*, char*);

/* Base vtable D_004DCF10 is set first, then the derived one. */
ByteEvent* cAtmosphericEffectMsg_ctor(ByteEvent* self, int value) {
    Event_Construct(self, D_004F5410);
    self->vtable = &D_004DCF10;
    self->vtable = &D_004DAE50;
    self->value = value;
    return self;
}
