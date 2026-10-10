#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
struct Npc_f4 { char pad[0xC]; int id; };
struct Think_f4 { Npc_f4* npc; int id; };
extern "C" {
extern char D_0049B670[];
extern char D_004EA190[];
void* Mem_Alloc(int, int, char*, int);
void func_0015B030(void*, Think_f4**);
}
extern "C" void func_0015AF50(Npc_f4* npc)
{
    Think_f4* t[1];
    Think_f4* p;
    {
        AllocGuard g;
        p = (Think_f4*)Mem_Alloc(0, 8, D_0049B670, 0x116);
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
    func_0015B030(D_004EA190, t);
}

