/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern char D_004DA930[];   /* AnimEvent vtable */
extern char D_00542B60[];   /* AnimEvent message type */
extern Message* cMessage_ctor_cMessageNameR(Message*, void*);

float func_0018A2C0(char* self) {
    return *(float*)(self + 156);
}

float cSkaRequestStream_AnimationPacket_GetDuration(char* self) {
    return *(float*)(self + 152);
}

void* cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(char* self) {
    return self + 76;
}

signed char cSkaRequestStream_AnimationPacket_GetInstruction(signed char* self) {
    return self[72];
}

AnimEvent* cSkaAnimEndedMessage_ctor_void(AnimEvent* self) {
    cMessage_ctor_cMessageNameR(&self->base, D_00542B60);
    self->base.vtable = D_004DA930;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    self->unk34 = 0.0f;
    return self;
}

Vec4* cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(Vec4* dst, Vec4* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    dst->w = src->w;
    return dst;
}
