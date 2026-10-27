#include "types.h"

typedef struct Obj2D35 {
    char pad00[0x30];
    void* owner; /* 0x30 */
} Obj2D35;

extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cNPC_SetFireMode(Obj2D35* self, int kind, int arg);
extern void cNetNPCMsgs_SendMessage(void* owner, int msg, int len, int a, int b, int c, int d);

/* Forwards to cNPC_SetFireMode when enabled, then sends message 0xC to the owner. */
void cNetNPC_SetFireMode(Obj2D35* self, int kind, int arg) {
    int enabled;
    if (g_IsMultiplayer) {
        enabled = D_005721C0;
    } else {
        enabled = 1;
    }
    if (enabled) {
        cNPC_SetFireMode(self, kind, arg);
    }
    cNetNPCMsgs_SendMessage(self->owner, 0xC, 8, (unsigned char)kind, arg, 0, 0);
}
