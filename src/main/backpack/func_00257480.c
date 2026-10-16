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
extern int D_004F7F30;
extern char D_004A7B50[];
void* Mem_Alloc(int heap, int size, char* file, int line);
Backpack* cBackpack_ctor(void* p, int rec);
void Backpack_AppendToList(int list, Backpack** bp);
void NetMap_BindReceiver(int a, int b, void* c);
}

static inline void* New_00257480(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004A7B50, line);
}

extern "C" Backpack* Backpack_CreateFromRecord(int rec)
{
    Backpack* bp;
    void* p = New_00257480(0x318, 0x16F);
    if (p) p = cBackpack_ctor(p, rec);
    bp = (Backpack*)p;
    Backpack_AppendToList(D_004F7F30, &bp);
    if (D_005721C8) {
        Backpack* b = bp;
        b->netid = b->id;
        if (!(D_005721C8 ? D_005721C0 : 1)) b->active = 0;
        int nid = b->netid;
        NetMap_BindReceiver(nid, NetObjId(), b);
    }
    return bp;
}
