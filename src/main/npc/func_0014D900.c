#include "types.h"
typedef struct Msg_0014D900 {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
    char pad29[7];
} Msg_0014D900;
typedef struct Self_0014D900 {
    char pad[0x30]; void* target; char pad34[0x9C - 0x34]; int prio;
    char padA0[0x124 - 0xA0]; int flags; float f128;
} Self_0014D900;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern void Event_Construct(Msg_0014D900* msg, void* name);
extern void Event_Send(Msg_0014D900* msg, void* target, int flags);
extern void cMessage_dtor(Msg_0014D900* msg, int flags);
#define SEND1(V) { Msg_0014D900 msg; Event_Construct(&msg, g_ActorActionMsgClass); msg.b28 = 0; msg.vtable = D_004E0840; msg.value = V; { void* t = self->target; msg.b20 = 1; Event_Send(&msg, t, 0); } msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
#define SEND0(V) { Msg_0014D900 msg; Event_Construct(&msg, g_ActorActionMsgClass); msg.b28 = 0; msg.vtable = D_004E0840; msg.value = V; Event_Send(&msg, self->target, 0); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
void NpcAi_RequestAction(Self_0014D900* self, unsigned char type, int prio, float f)
{
    switch (type) {
    case 9:
        if (prio >= self->prio) {
            self->prio = prio;
            SEND1(2)
            self->flags &= ~1;
        }
        break;
    case 1:
        if (prio >= self->prio) {
            self->prio = prio;
            SEND1(1)
            self->flags |= 1;
        }
        break;
    case 2:
        SEND0(8)
        self->flags |= 2;
        break;
    case 10:
        SEND1(0xA)
        self->flags &= ~4;
        break;
    case 4:
        SEND1(9)
        self->flags |= 4;
        break;
    case 8:
        if (!(self->flags & 8))
            SEND0(0x40)
        self->flags |= 8;
        self->f128 = f;
        break;
    case 11:
        if (self->flags & 8) {
            SEND0(0x41)
            self->flags &= ~8;
        }
        break;
    }
}