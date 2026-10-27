#include "types.h"
extern void cNetNPCMsgs_SendMessage(void* owner, int type, int size, unsigned char a, int b, int c, int d);
typedef struct { char pad[0xC]; int c; } A5_002D4680_M;
typedef struct { char pad[0x30]; void* owner; char pad2[0x154 - 0x34]; float t; } A5_002D4680;
void cNetNPC_Sound(A5_002D4680* self, int v, A5_002D4680_M* m) {
    if (self->t <= 0.0f) {
        cNetNPCMsgs_SendMessage(self->owner, 0x3B, 8, v, m->c, 0, 0);
        self->t = 2.0f;
    }
}
