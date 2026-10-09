/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern char D_004DA930[];   /* AnimEvent vtable */
extern char D_004DFD80[];   /* Message base vtable */

/* AnimEvent copy constructor. */
AnimEvent* AnimEvent_Copy(AnimEvent* self, AnimEvent* src) {
    self->base.vtable = D_004DFD80;
    self->base.unk04 = src->base.unk04;
    self->base.unk08 = src->base.unk08;
    self->base.unk0C = src->base.unk0C;
    self->base.unk10 = src->base.unk10;
    self->base.unk14 = src->base.unk14;
    self->base.unk18 = src->base.unk18;
    self->base.unk1C = src->base.unk1C;
    self->base.unk20 = src->base.unk20;
    self->base.vtable = D_004DA930;
    self->unk24 = src->unk24;
    self->unk28 = src->unk28;
    self->unk2C = src->unk2C;
    self->unk30 = src->unk30;
    self->unk34 = src->unk34;
    return self;
}

int* func_001ADFE0(int* self, int value) {
    *self = value;
    return self;
}

/* Store a Vec4 at +0x08 and set the "valid" byte at +0x05. */
char* func_001ADFF0(char* self, Vec4* v) {
    Vec4* dst = (Vec4*)(self + 8);

    dst->x = v->x;
    dst->y = v->y;
    dst->z = v->z;
    dst->w = v->w;
    self[5] = 1;
    return self;
}
