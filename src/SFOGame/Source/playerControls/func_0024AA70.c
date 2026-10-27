#include "types.h"
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int value;              /* 0x24 */
    unsigned char flag;     /* 0x28 */
    char pad[7];
} Msg;
typedef struct { char pad[0x3524]; void* owner; } Player;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern int cWeapon_CanReload(void* owner);
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* msg, void* target, int flags);
extern void cMessage_dtor(Msg* msg, int flags);
/* When enabled and the owner is valid, sends the player a timed message (60). */
void cPlayerControls_HandleReloadButtonPress(void* self, int enable, Player* p)
{
    Msg msg;
    if (enable && cWeapon_CanReload(p->owner)) {
        cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
        msg.vtable = D_004E0840;
        msg.value = 0x3C;
        msg.flag = 0;
        QueueMessage_cMessageR_cSystemP_int(&msg, p, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
}
