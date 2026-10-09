/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004D97F0;
extern char D_004F53E8[];
extern ByteEvent* Event_Construct(ByteEvent*, char*);

ByteEvent* func_0020E860(ByteEvent* self, int value) {
    Event_Construct(self, D_004F53E8);
    self->vtable = &D_004D97F0;
    self->value = value;
    return self;
}
