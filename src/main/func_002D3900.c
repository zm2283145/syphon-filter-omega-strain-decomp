#include "types.h"

typedef struct { char pad[0x30]; void* owner; } Obj2D3;

extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void cNPC_RequestAction(Obj2D3* self, int a, int b);
extern void NetEvent_Send(void* owner, int type, int size, unsigned char a, int b, int c, int d);

/* Applies the change locally (unless suppressed by the global flags) and broadcasts it. */
void func_002D3900(Obj2D3* self, int a, int b)
{
    if (D_005721C8 ? D_005721C0 : 1)
        cNPC_RequestAction(self, a, b);
    NetEvent_Send(self->owner, 0x14, 8, a, b, 0, 0);
}
