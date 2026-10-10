#include "types.h"
typedef struct { char pad[0x30]; void* owner; } B5eObj;
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void cNPC_v71(B5eObj* o, float x);
extern void NetEvent_Send(void* owner, int id, int size, unsigned int v, int a, int b, int c);
void func_002D3C20(B5eObj* o, float x) {
    if (D_005721C8 ? D_005721C0 : 1) {
        cNPC_v71(o, x);
    }
    NetEvent_Send(o->owner, 0x33, 8, (unsigned int)x, 0, 0, 0);
}