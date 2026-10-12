/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern void Renderer_ClearRect(Obj37A1C0* self, int a1, int a2, int a3, int a4, int a5);

/* Forwards to Renderer_ClearRect with the object's unk1C/unk20 pair. */
void func_0037A1C0(Obj37A1C0* self, int a1, int a2, int a3) {
    Renderer_ClearRect(self, self->unk1C, self->unk20, a1, a2, a3);
}
