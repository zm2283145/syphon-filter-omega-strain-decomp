#include "types.h"
typedef struct { char pad[0x30]; void* owner; } B5eObj;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cNPC_v71(B5eObj* o, float x);
extern void NetEvent_Send(void* owner, int id, int size, unsigned int v, int a, int b, int c);
void cNetNPC_ActivateByRadius(B5eObj* o, float x) {
    if (g_IsMultiplayer ? D_005721C0 : 1) {
        cNPC_v71(o, x);
    }
    NetEvent_Send(o->owner, 0x33, 8, (unsigned int)x, 0, 0, 0);
}