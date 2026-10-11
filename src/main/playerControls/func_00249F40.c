#include "types.h"
typedef struct Msg_00249F40 {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
    char pad29[7];
} Msg_00249F40;
typedef struct Pl_00249F40 { char pad[0x320C]; int state; } Pl_00249F40;
typedef struct In_00249F40 { char pad[0x24]; unsigned char b24; char pad25[0xAC - 0x25]; unsigned char held; } In_00249F40;
extern char D_0055D480[];
extern char D_004E0840[];
extern void Event_Construct(Msg_00249F40* msg, void* name);
extern void Event_Send(Msg_00249F40* msg, void* target, int flags);
extern void cMessage_dtor(Msg_00249F40* msg, int flags);
extern int func_0024A820(In_00249F40* in);
extern int PlayerInput_CrouchToggle(In_00249F40* in, Pl_00249F40* p);
#define SENDB(V) { Msg_00249F40 msg; Event_Construct(&msg, D_0055D480); msg.vtable = D_004E0840; msg.value = V; msg.b20 = 1; msg.b28 = 0; Event_Send(&msg, p, 1); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
#define SEND(V) { Msg_00249F40 msg; Event_Construct(&msg, D_0055D480); msg.vtable = D_004E0840; msg.b20 = 1; msg.value = V; msg.b28 = 0; Event_Send(&msg, p, 1); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
void PlayerInput_HandleCross(In_00249F40* in, Pl_00249F40* p, float v)
{
    int t = 1;
    unsigned char pressed;
    unsigned char edge;
    if (v <= 0.0f)
        t = 0;
    pressed = t;
    edge = !in->held && pressed;
    in->held = pressed;
    if (edge || (func_0024A820(in) && pressed)) {
        if (PlayerInput_CrouchToggle(in, p))
            pressed = 0;
    }
    if (p->state == 0x10) {
        if (pressed)
            SEND(0x1C)
        else
            SEND(0x1D)
    }
    if (pressed)
        SEND(0x10)
    if (pressed && !in->b24)
        SENDB(1)
    else
        SENDB(2)
}