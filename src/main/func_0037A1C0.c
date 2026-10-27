/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern void XLib_ClearActiveBuffer(Obj37A1C0* self, int a1, int a2, int a3, int a4, int a5);

/* Forwards to XLib_ClearActiveBuffer with the object's unk1C/unk20 pair. */
void XLib_ClearScreen_tIRGBAR_bool_uint(Obj37A1C0* self, int a1, int a2, int a3) {
    XLib_ClearActiveBuffer(self, self->unk1C, self->unk20, a1, a2, a3);
}
