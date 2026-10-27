#include "types.h"

typedef struct { char pad[0x30]; void* owner; } Obj2D3;

extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cNPC_RequestAction(Obj2D3* self, int a, int b);
extern void cNetNPCMsgs_SendMessage(void* owner, int type, int size, unsigned char a, int b, int c, int d);

/* Applies the change locally (unless suppressed by the global flags) and broadcasts it. */
void cNetNPC_RequestAction(Obj2D3* self, int a, int b)
{
    if (g_IsMultiplayer ? D_005721C0 : 1)
        cNPC_RequestAction(self, a, b);
    cNetNPCMsgs_SendMessage(self->owner, 0x14, 8, a, b, 0, 0);
}
