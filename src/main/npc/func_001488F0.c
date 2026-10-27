#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct P2_88F0 { float x; float y; };
struct Act_88F0 { char pad[0xC]; int id; };
struct Npc_88F0 { VPAD32(a) virtual unsigned char IsAuthority(); char pad4[0x2C]; void* net; char pad34[0x10]; char ai[0xB0]; int targetId; char padF8[8]; float px; float py; int x108; int x10C; };
extern "C" {
void cNetNPCMsgs_SendMessage(void*, int, int, int, int, int, int);
void cStateMachine_ChangeState(void*, int, int);
extern unsigned char g_IsMultiplayer;
}
/* request mode 9 toward a target (networked: broadcast event 0x32 first) */
#pragma push
#pragma opt_propagation off
extern "C" void cNPC_Follow_cGOBJP_float_float(Npc_88F0* self, Act_88F0* t, float x, float y)
{
    if (g_IsMultiplayer && self->IsAuthority() == 1) { int id = t ? t->id : -1; int ix = *(int*)&x; int iy = *(int*)&y; cNetNPCMsgs_SendMessage(self->net, 0x32, 4, id, ix, iy, 0); }
    if (t) {
        self->targetId = t->id;
        self->px = x;
        self->py = y;
        self->x108 = 0;
        self->x10C = 0;
        cStateMachine_ChangeState(self->ai, 9, 100);
    }
}
#pragma pop
