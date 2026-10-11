#include "types.h"
#include "message_pack.h"
typedef struct { char pad[0x78]; int netId; } G05A0;
typedef struct { char pad[0x1C]; int size; char pad2[4]; G05A0* a; G05A0* b; } E05A0;
int cAINodeMsg_v02(E05A0* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    if (sz >= 0x10 && buf) {
        int* b = (int*)buf;
        Event_PackHeader(e, a1, type, a3, a4, sz, buf);
        if (e->a) b[2] = e->a->netId; else b[2] = -1;
        if (e->b) b[3] = e->b->netId; else b[3] = -1;
        e->size = 0x40;
    }
    return -1;
}