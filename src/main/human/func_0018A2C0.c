/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern char D_004DA930[];   /* AnimEvent vtable */
extern char D_00542B60[];   /* AnimEvent message type */
extern Message* Event_Construct(Message*, void*);

float func_0018A2C0(char* self) {
    return *(float*)(self + 156);
}

float func_0018A2D0(char* self) {
    return *(float*)(self + 152);
}

void* func_0018A2E0(char* self) {
    return self + 76;
}

signed char func_0018A2F0(signed char* self) {
    return self[72];
}

AnimEvent* AnimEvent_Construct(AnimEvent* self) {
    Event_Construct(&self->base, D_00542B60);
    self->base.vtable = D_004DA930;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    self->unk34 = 0.0f;
    return self;
}

Vec4* Vec4_Copy_18A350(Vec4* dst, Vec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}
