#include "types.h"
typedef struct { void* vtable; char base[0x18]; int size; unsigned char kind; char pad[3]; unsigned char value; unsigned char extra; char pad2[0xA]; } Msg_5140;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x346B - 0x50]; unsigned char value; } Hum_5140;
int Event_Construct(Msg_5140*, void*);
int Event_Send(Msg_5140*, void*, int);
Hum_5140* GObj_IdentityB(int);
int cMessage_dtor(Msg_5140*, int);
extern int g_HumanActorClassKey;
extern char D_004DA9D0[];
extern char D_004DCF10[];
extern char D_004EEE98[];
extern unsigned char g_IsMultiplayer;
static inline void Set_5140(Hum_5140* self, unsigned char value, int silent) {
    Msg_5140 msg;
    self->value = value;
    if (g_IsMultiplayer && !silent) {
        Event_Construct(&msg, D_004EEE98);
        msg.vtable = D_004DA9D0;
        msg.extra = 1;
        msg.kind = 4;
        msg.size = 0x40;
        msg.value = value;
        Event_Send(&msg, self, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
#pragma push
#pragma opt_propagation off
int Script_SetNotGasable(int* args)
{
    Hum_5140* s;
unsigned char v;
Hum_5140* g;
    v = args[1] != 0;
    g = GObj_IdentityB(args[0]);
    if (g && g->classKey == g_HumanActorClassKey) { s = g; Set_5140(s, v, 0); }
    return 0;
}
#pragma pop
