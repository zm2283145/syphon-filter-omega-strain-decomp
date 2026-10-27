/*
 * SFOGame/Source/npc: 2 files, 0015AF30-0015AF50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015AF30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

void std_list_cActiveListItemPtr_generic_iterator_opCast(Word* dst, Word* src) {
    dst->value = src->value;
}

Word* std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0015AF30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015AF30 */

/* merge_units: begin func_0015AF50 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0015AF50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015AF50 */
