#include "types.h"

typedef struct { unsigned char b0 : 1; unsigned char b1 : 1; unsigned char flag : 1; } NpcBits;
typedef struct { char pad[0x30]; void* owner; char pad2[0x10D]; NpcBits bits; } cNPC;

extern unsigned char D_005721C8; /* networked game */
extern unsigned char D_005721C0; /* is host */
extern void NetEvent_Send(void* owner, int type, int size, unsigned char a, int b, int c, int d);

static inline int IsAuthority(void)
{
    return D_005721C8 ? D_005721C0 : 1;
}

/* cNPC virtual 0x56: sets flag bit 2 and broadcasts it in network games. */
void cNPC_v56(cNPC* self, int on)
{
    self->bits.flag = on;
    if (D_005721C8 && IsAuthority())
        NetEvent_Send(self->owner, 0x18, 4, (unsigned char)on, 0, 0, 0);
}
