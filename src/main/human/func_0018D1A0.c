#include "types.h"
#include "human_types.h"
#include "canonical_key_copy.h"
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key_18D1A0;
typedef struct { char pad[0x320C]; int state; char pad2[0x324C - 0x3210]; int flags; char pad3[0x3314 - 0x3250]; int target; } O_18D1A0;
extern char D_004DA930[];
extern char D_00542B60[];
extern Message* Event_Construct(Message*, void*);
extern void cMessage_dtor(AnimEvent* msg, int flags);
extern void Secondary_RequestOneShot(int target, Key_18D1A0* key, int n, AnimEvent* ev);
static inline AnimEvent* AnimEvent_Init_18D1A0(AnimEvent* self)
{
    Event_Construct(&self->base, D_00542B60);
    self->base.vtable = D_004DA930;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    self->unk30 = 0;
    self->unk34 = 0.0f;
    return self;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void func_0018D1A0(O_18D1A0* o)
{
    int st;
    if (o->target == 0) return;
    st = o->state;
    if (st == 0 || st == 3) {
        Key_18D1A0 key;
        AnimEvent ev;
        AnimEvent* pe = &ev; AnimEvent_Init_18D1A0(pe);
        CKC_COPY_S(key.c, "flashbanghide")
        Secondary_RequestOneShot(o->target, &key, 1, &ev);
        ev.base.vtable = D_004DA930;
        cMessage_dtor(&ev, 0);
        o->flags |= 0x100;
    }
}
#pragma pop

