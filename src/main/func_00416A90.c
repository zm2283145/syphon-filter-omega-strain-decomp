/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E0960[];         /* derived vtable */
extern char D_004E09B0[];         /* GUI root vtable */
extern int D_00572130;            /* GUI object instance counter */

/* Constructor of a direct GuiObject subclass. */
GuiObject* func_00416A90(GuiObject* self) {
    self->vtable = D_004E09B0;
    D_00572130 = D_00572130 + 1;
    self->vtable = D_004E0960;
    self->unk04 = 0;
    return self;
}
