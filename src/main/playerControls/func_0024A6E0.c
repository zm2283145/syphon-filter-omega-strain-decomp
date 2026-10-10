#include "types.h"
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char b20;  /* 0x20 */
    char pad21[3];
    int action;         /* 0x24 */
    unsigned char b28;  /* 0x28 */
} TryStandMsg_e8;
typedef struct { char pad[0x3D2]; unsigned char crouchBlock; } TryStandPhys_e8;
typedef struct {
    char pad[0x3204];
    int flags;                  /* 0x3204 */
    char pad3208[0x3310 - 0x3208];
    TryStandPhys_e8* phys;      /* 0x3310 */
} TryStandActor_e8;
extern char D_0055D480[];
extern char D_004E0840[];
extern void Event_Construct(TryStandMsg_e8* msg, void* name);
extern void Event_Send(TryStandMsg_e8* msg, void* target, int flags);
extern void cMessage_dtor(TryStandMsg_e8* msg, int flags);
int PlayerInput_TryStand(void* self, TryStandActor_e8* actor)
{
    int blocked = ((actor->flags >> 4) & 1) && actor->phys && actor->phys->crouchBlock;
    if (!blocked) {
        TryStandMsg_e8 msg;
        Event_Construct(&msg, D_0055D480);
        msg.vtable = D_004E0840;
        msg.action = 10;
        msg.b20 = 1;
        msg.b28 = 0;
        Event_Send(&msg, actor, 1);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
        return 1;
    }
    return 0;
}