/*
 * SFOGame/Source/backpack: 2 files, 00257450-00257480
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00257450 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_reserve(int, int);

int std_vector_cBackpackPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_cBackpackPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00257450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257450 */

/* merge_units: begin func_00257480 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
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
static inline void merge_flush_func_00257480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00257480 */
