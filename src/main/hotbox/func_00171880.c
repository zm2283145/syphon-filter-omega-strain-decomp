#include "types.h"
typedef struct { void* vt; char pad[0x1C]; unsigned char kind; char pad21[0x1F]; } Msg_1880;
typedef struct { void* target; } Lnk_1880;
typedef struct { char pad[0x68]; Lnk_1880* link; char pad6c[0x28]; int x94; } Obj_1880;
void cGOBJTriggerEventMsg_ctor(Msg_1880* m, int type, int a, int b, Obj_1880* src);
int Event_Send(Msg_1880*, void*, int);
int cMessage_dtor(Msg_1880*, int);
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern char D_004DAF10[];
static inline unsigned char IsLocal_1880(void) { unsigned char v; if (D_005721C8) v = D_005721C0; else v = 1; return v; }
/* send a trigger event (type 7) to the linked target when networked */
int func_00171880(Obj_1880* self, int arg)
{
    if (D_005721C8) {
        Msg_1880 m;
        cGOBJTriggerEventMsg_ctor(&m, 7, self->x94, arg, self);
        m.kind = IsLocal_1880() ? 1 : 2;
        Event_Send(&m, self->link->target, 0);
        m.vt = D_004DAF10;
        cMessage_dtor(&m, 0);
    }
    return 1;
}
