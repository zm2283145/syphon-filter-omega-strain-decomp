/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern char D_004DCD70[];   /* cAIGOBJMsg vtable */
extern char D_004DFD80[];   /* Message base vtable */
extern char D_004E0840[];   /* ArgMsg vtable */
extern Message* Event_Construct(Message*, void*);

/* Copy constructor for a message with an int and a byte argument. */
ArgMsg* cMessage_ctor3(ArgMsg* self, ArgMsg* src) {
    self->base.vtable = D_004DFD80;
    self->base.unk04 = src->base.unk04;
    self->base.unk08 = src->base.unk08;
    self->base.unk0C = src->base.unk0C;
    self->base.unk10 = src->base.unk10;
    self->base.unk14 = src->base.unk14;
    self->base.unk18 = src->base.unk18;
    self->base.unk1C = src->base.unk1C;
    self->base.unk20 = src->base.unk20;
    self->base.vtable = D_004E0840;
    self->arg0 = src->arg0;
    self->arg1 = src->arg1;
    return self;
}

ArgMsg* cAIGOBJMsg_ctor(ArgMsg* self, void* type, int arg) {
    Event_Construct(&self->base, type);
    self->base.vtable = D_004DCD70;
    self->arg0 = arg;
    self->base.unk20 = 2;
    return self;
}

int func_001AD8B0(char* self) {
    return *(int*)(self + 48);
}
