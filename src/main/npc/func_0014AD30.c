#include "types.h"
typedef struct {
    char pad00[0x30];
    void* owner;
    char pad34[0x98 - 0x34];
    float f98;
    char pad9C[0x141 - 0x9C];
    unsigned char lo7 : 7;
    unsigned char flag : 1;
} NPC_AD30;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void NetEvent_Send(void* owner, int type, int size, int a, int b, int c, int d);
void cNPC_v71(NPC_AD30* self, float f)
{
    if (D_005721C8) {
        if (D_005721C8 ? D_005721C0 : 1)
            NetEvent_Send(self->owner, 0x33, 4, (unsigned int)f, 0, 0, 0);
    }
    if (f < 1e-5f) self->f98 = 0.0f;
    else self->f98 = f * f;
    self->flag = 1;
}