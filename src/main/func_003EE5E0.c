/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int func_003EE360(Unk3EE5E0*, Vec4*);

/* Stores a vector at +0xA0, then forwards it to func_003EE360. */
int func_003EE5E0(Unk3EE5E0* self, Vec4* v) {
    float x;
    float y;
    float z;
    float w;

    x = v->x;
    self->unkA0.x = x;
    y = v->y;
    self->unkA0.y = y;
    z = v->z;
    self->unkA0.z = z;
    w = v->w;
    self->unkA0.w = w;
    return func_003EE360(self, v);
}
