#include "types.h"
typedef struct {
    void* vtable;
    char base[0x18];
    int x1C;
    unsigned char kind;
    char pad21[0xB];
    unsigned char op;
    char pad2D[7];
    char slot;
    char pad35[3];
    int value;
} Msg_INV;
typedef struct { int a; int b; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x88 - 0x74]; void* owner; } INV;
extern char D_0052ACC8[];
extern char D_004DE610[];
extern unsigned char D_005721C8;
extern void Event_Construct(Msg_INV* msg, void* name);
extern void Event_Send(Msg_INV* msg, void* target, int flags);
extern void cMessage_dtor(Msg_INV* msg, int flags);
extern int func_00142AE0(INV* self, unsigned char slot);
int func_001429D0(INV* self, unsigned char slot, int req, int quiet)
{
    int room = func_00142AE0(self, slot);
    int n = (req < room || quiet) ? req : room;
    self->e[slot].d += n;
    if (D_005721C8 && !quiet) {
        Msg_INV msg;
        Event_Construct(&msg, D_0052ACC8);
        msg.vtable = D_004DE610;
        msg.slot = slot;
        msg.value = req;
        msg.op = 4;
        msg.x1C = 0x40;
        msg.kind = 4;
        Event_Send(&msg, self->owner, 0);
        msg.vtable = D_004DE610;
        cMessage_dtor(&msg, 0);
    }
    return n;
}