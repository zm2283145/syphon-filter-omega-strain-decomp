/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copy and the action-message copy constructor.
 */

#include "types.h"
#include "ai_types.h"

extern char D_004D92A0[];
extern char D_004D92C0[];
extern char D_004DFD80[]; /* cMessage vtable */

Word* func_0016F7E0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

cActionMsg* cMessage_ctor2(cActionMsg* self, cActionMsg* src) {
    self->base.vtable = D_004DFD80;
    self->base.unk04 = src->base.unk04;
    self->base.unk08 = src->base.unk08;
    self->base.unk0C = src->base.unk0C;
    self->base.unk10 = src->base.unk10;
    self->base.unk14 = src->base.unk14;
    self->base.unk18 = src->base.unk18;
    self->base.unk1C = src->base.unk1C;
    self->base.unk20 = src->base.unk20;
    self->base.vtable = D_004D92A0;
    self->event = src->event;
    self->action = src->action;
    self->amplitude = src->amplitude;
    self->unk2C = src->unk2C;
    self->base.vtable = D_004D92C0;
    self->sender = src->sender;
    return self;
}
