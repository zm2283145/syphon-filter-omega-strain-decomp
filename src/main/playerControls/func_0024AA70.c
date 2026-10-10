#include "types.h"
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int value;              /* 0x24 */
    unsigned char flag;     /* 0x28 */
    char pad[7];
} Msg;
typedef struct { char pad[0x3524]; void* owner; } Player;
extern char D_0055D480[];
extern char D_004E0840[];
extern int func_00143560(void* owner);
extern void Event_Construct(Msg* msg, void* name);
extern void Event_Send(Msg* msg, void* target, int flags);
extern void cMessage_dtor(Msg* msg, int flags);
/* When enabled and the owner is valid, sends the player a timed message (60). */
void func_0024AA70(void* self, int enable, Player* p)
{
    Msg msg;
    if (enable && func_00143560(p->owner)) {
        Event_Construct(&msg, D_0055D480);
        msg.vtable = D_004E0840;
        msg.value = 0x3C;
        msg.flag = 0;
        Event_Send(&msg, p, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
}
