#include "types.h"
typedef struct Msg_00151A90 {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
    char pad29[7];
} Msg_00151A90;
typedef struct Tgt_00151A90 { char pad[0x320C]; int state; } Tgt_00151A90;
typedef struct Self_00151A90 { char pad[0x30]; Tgt_00151A90* target; char pad34[0x114 - 0x34]; int mode; } Self_00151A90;
typedef struct Ev_00151A90 { char pad[0x24]; int type; } Ev_00151A90;
extern char D_0055D480[];
extern char D_004E0840[];
extern void Event_Construct(Msg_00151A90* msg, void* name);
extern void Event_Send(Msg_00151A90* msg, void* target, int flags);
extern void cMessage_dtor(Msg_00151A90* msg, int flags);
int NpcAi_HandleLivingMessage(Self_00151A90* self, Ev_00151A90* ev)
{
    switch (ev->type) {
    case 6: {
        int v = self->mode == 4 ? 0x11 : 0x13;
        Msg_00151A90 msg;
        Event_Construct(&msg, D_0055D480);
        msg.value = v;
        msg.b28 = 0;
        msg.vtable = D_004E0840;
        { Tgt_00151A90* t = self->target;
        msg.b20 = 1;
        Event_Send(&msg, t, 0); }
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        break;
    }
    case 9:
        if (self->mode == 4) {
            Msg_00151A90 msg;
            Event_Construct(&msg, D_0055D480);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x11;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            Event_Send(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        }
        break;
    case 8:
        {
        int m = self->mode;
        if (m == 4) {
            Msg_00151A90 msg;
            Event_Construct(&msg, D_0055D480);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0xF;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            Event_Send(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 11) {
            Msg_00151A90 msg;
            Event_Construct(&msg, D_0055D480);
            msg.b28 = 0;
            msg.vtable = D_004E0840;
            msg.value = 0x10;
            { Tgt_00151A90* t = self->target;
            msg.b20 = 1;
            Event_Send(&msg, t, 0); }
            msg.vtable = D_004E0840;
            cMessage_dtor(&msg, 0);
        } else if (m == 3) {
            if (self->target->state != 0x10) {
                Msg_00151A90 msg;
                Event_Construct(&msg, D_0055D480);
                msg.b28 = 0;
                msg.vtable = D_004E0840;
                msg.value = 0x1A;
                Event_Send(&msg, self->target, 0);
                msg.vtable = D_004E0840;
                cMessage_dtor(&msg, 0);
            }
        }
        }
        break;
    default:
        return 0;
    }
    return 1;
}