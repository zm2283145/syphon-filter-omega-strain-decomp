#include "types.h"
typedef struct { void* vtable; char base[0x18]; int size; unsigned char kind; char pad[0xF]; } Msg_5410;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; int holster; } Hum_5410;
int cMessage_ctor_cMessageNameR(Msg_5410*, void*);
int QueueMessage_cMessageR_cSystemP_int(Msg_5410*, void*, int);
Hum_5410* cGOBJ_SOBJ_convert(int);
int cWeapon_ForceHolster(int);
int cMessage_dtor(Msg_5410*, int);
extern int g_HumanActorClassKey;
extern char D_004DA9B0[];
extern char D_004DCF10[];
extern char D_004EF030[];
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
static inline unsigned char IsLocal_5410(void) { unsigned char v; if (g_IsMultiplayer) v = D_005721C0; else v = 1; return v; }
static inline void Holster_5410(Hum_5410* selfp) {
    Msg_5410 msg;
    Hum_5410* self = selfp;
    cWeapon_ForceHolster(self->holster);
    if (g_IsMultiplayer) {
        if (IsLocal_5410()) {
            cMessage_ctor_cMessageNameR(&msg, D_004EF030);
            msg.vtable = D_004DA9B0;
            msg.size = 0x40;
            msg.kind = 8;
            QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
            msg.vtable = D_004DCF10;
            cMessage_dtor(&msg, 0);
        }
    }
}
/* script: force the target human to holster; notify when networked and local */
#pragma push
#pragma opt_propagation off
int Script_ForceHolster(int* args)
{
    Hum_5410* g = cGOBJ_SOBJ_convert(args[0]);
    if (g && g->classKey == g_HumanActorClassKey) Holster_5410(g);
    return 0;
}
#pragma pop
