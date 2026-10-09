/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern char D_004E0840[];         /* Msg3E43D0 vtable */
extern char D_0055D480[];         /* Msg3E43D0 type descriptor */
extern void* cMessage_ctor5(void* self, void* type, void* arg);

Vec4* func_003E4920(Vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
    return v;
}

/* Builds the message from explicit values. */
Msg3E43D0* func_003E4940(Msg3E43D0* self, void* arg, int a, int b) {
    cMessage_ctor5(self, D_0055D480, arg);
    self->vtable = D_004E0840;
    self->unk24 = a;
    self->unk28 = b;
    return self;
}
