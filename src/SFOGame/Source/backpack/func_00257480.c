#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}

struct Backpack {
    char pad0[0xC];
    int id;              /* 0x0C */
    int netid;           /* 0x10 */
    unsigned char active; /* 0x14 */
};

extern "C" {
extern int g_BackpackList;
extern char D_004A7B50[];
void* cMemMan_Allocate(int heap, int size, char* file, int line);
Backpack* cBackpack_ctor(void* p, int rec);
void std_vector_cBackpackPtr_push_back(int list, Backpack** bp);
void cNetObj_AddSystem(int a, int b, void* c);
}

static inline void* New_00257480(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, D_004A7B50, line);
}

extern "C" Backpack* cBackpack_NewBackpack_cPopulationR(int rec)
{
    Backpack* bp;
    void* p = New_00257480(0x318, 0x16F);
    if (p) p = cBackpack_ctor(p, rec);
    bp = (Backpack*)p;
    std_vector_cBackpackPtr_push_back(g_BackpackList, &bp);
    if (g_IsMultiplayer) {
        Backpack* b = bp;
        b->netid = b->id;
        if (!(g_IsMultiplayer ? D_005721C0 : 1)) b->active = 0;
        int nid = b->netid;
        cNetObj_AddSystem(nid, NetObjId(), b);
    }
    return bp;
}
