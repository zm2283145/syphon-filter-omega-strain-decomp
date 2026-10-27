#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
struct Npc_f4 { char pad[0xC]; int id; };
struct Think_f4 { Npc_f4* npc; int id; };
extern "C" {
extern char D_0049B670[];
extern char g_NpcThinkList[];
void* cMemMan_Allocate(int, int, char*, int);
void std_list_cActiveListItemPtr_push_back(void*, Think_f4**);
}
extern "C" void cNPC_AddToActiveList(Npc_f4* npc)
{
    Think_f4* t[1];
    Think_f4* p;
    {
        AllocGuard g;
        p = (Think_f4*)cMemMan_Allocate(0, 8, D_0049B670, 0x116);
    }
    if (p) {
        int* src;
        p->id = -1;
        p->npc = npc;
        if (npc) {
            src = &npc->id;
        } else {
            int def[1];
            def[0] = -1;
            src = def;
        }
        p->id = *src;
    }
    t[0] = p;
    std_list_cActiveListItemPtr_push_back(g_NpcThinkList, t);
}

