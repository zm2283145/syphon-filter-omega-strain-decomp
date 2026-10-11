#include "types.h"
#include "message_pack.h"
typedef struct { char pad[0x78]; int netId; } GFC80;
typedef struct { char pad[0x1C]; int size; char pad2[4]; GFC80* a; GFC80* b; } EFC80;
extern int D_004FF100;
static inline void pack_FC80(EFC80* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    if (sz >= 0x10 && buf) {
        int* b = (int*)buf;
        Event_PackHeader(e, a1, type, a3, a4, sz, buf);
        if (e->a) b[2] = e->a->netId; else b[2] = -1;
        if (e->b) b[3] = e->b->netId; else b[3] = -1;
        e->size = 0x40;
    }
}
int cAIDestinationReachedMsg_v02(EFC80* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    int r = -1;
    if (sz >= 0x10 && buf) {
        pack_FC80(e, a1, type, a3, a4, sz, buf);
        if (type) {
            r = 0x10;
            *type = D_004FF100;
        }
    }
    return r;
}