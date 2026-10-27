/*
 * SFOGame/Source/npc: 2 files, 0015B030-0015B060
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015B030 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern Iter* std_list_deleter_voidPtr_insert(Iter* out, Tree* t, Iter* hint, int value);

/* map insert(value): inserts with an end() hint, result iterator in out[1]. */
Iter* std_list_cActiveListItemPtr_push_back(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}
static inline void merge_flush_func_0015B030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015B030 */

/* merge_units: begin func_0015B060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { int key; int val; int x8; } Ent_B060;
typedef struct N_B060 { struct N_B060* prev; struct N_B060* next; Ent_B060* e; } N_B060;
typedef struct { int a; int b; } It2_B060;
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_0049B670[];
extern char D_004EA1B0[];
void std_list_deleter_voidPtr_begin_void(N_B060** out, void* list);
void func_0015AD60(N_B060** out, N_B060** in);
void func_0015AD50(N_B060** out, void* list);
void func_0015AD40(N_B060** out, N_B060** in);
void std_list_cEnabledListItemPtr_push_back(void* list, Ent_B060** e);
}
typedef struct { char pad[0xC]; int id; } Ctl_B060;
typedef struct { char pad[0x30]; Ctl_B060* ctl; } NPC_B060;
static inline void Begin(N_B060** out) { N_B060* t; std_list_deleter_voidPtr_begin_void(&t, D_004EA1B0); func_0015AD60(out, &t); }
static inline N_B060* End(N_B060** out) { N_B060* t; func_0015AD50(&t, D_004EA1B0); func_0015AD40(out, &t); return *out; }
static inline void Ent_Init(Ent_B060* p, Ctl_B060* c) { p->key = -1; p->key = c->id; p->val = 0; p->x8 = 0; }
extern "C" int cNPC_GetEnabled(NPC_B060* self)
{
    Ent_B060* found = 0;
    N_B060* end;
    N_B060* it;
    N_B060* n;
    Begin(&it);
    n = it;
    for (; n != End(&end); n = n->next) {
        if (n->e->key == self->ctl->id) {
            found = n->e;
            break;
        }
        }
    if (!found) {
        Ent_B060* p;
        {
            AllocGuard g;
            p = (Ent_B060*)cMemMan_Allocate(0, 0xC, D_0049B670, 0xFF);
        }
        if (p)
            Ent_Init(p, self->ctl);
        found = p;
        std_list_cEnabledListItemPtr_push_back(D_004EA1B0, &found);
    }
    return found->val;
}
static inline void merge_flush_func_0015B060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015B060 */
