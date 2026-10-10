#include "types.h"

typedef struct Obj2D35 {
    char pad00[0x30];
    void* owner; /* 0x30 */
} Obj2D35;

extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void cNPC_v46(Obj2D35* self, int kind, int arg);
extern void NetEvent_Send(void* owner, int msg, int len, int a, int b, int c, int d);

/* Forwards to cNPC_v46 when enabled, then sends message 0xC to the owner. */
void func_002D3510(Obj2D35* self, int kind, int arg) {
    int enabled;
    if (D_005721C8) {
        enabled = D_005721C0;
    } else {
        enabled = 1;
    }
    if (enabled) {
        cNPC_v46(self, kind, arg);
    }
    NetEvent_Send(self->owner, 0xC, 8, (unsigned char)kind, arg, 0, 0);
}
