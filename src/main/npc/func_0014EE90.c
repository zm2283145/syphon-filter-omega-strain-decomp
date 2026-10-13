#include "types.h"
typedef struct { int pad[3]; int key; } Tgt_EE90;
typedef struct { Tgt_EE90* node; int key; } H_EE90;
typedef struct { H_EE90 h; int pad8; int prio; } Dat_EE90;
typedef struct N_EE90 { struct N_EE90* prev; struct N_EE90* next; Dat_EE90 d; } N_EE90;
typedef struct { N_EE90* prev; N_EE90* next; } L_EE90;
typedef struct { char pad[0x1B8]; void* list; } NPC_EE90;
extern L_EE90* func_0014EE70(void* list);
extern void func_0014EE60(N_EE90** it, N_EE90* n);
extern void func_0014EE50(N_EE90** it, L_EE90* l);
static inline Tgt_EE90* H_Get(H_EE90* o)
{
    Tgt_EE90* n = o->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != o->key) ok = 0;
    return ok ? n : 0;
}
Tgt_EE90* NpcLook_FindFacingObject(NPC_EE90* self)
{
    N_EE90* it;
    N_EE90* end;
    Tgt_EE90* best = 0;
    int bestPrio = 0;
    N_EE90* n;
    func_0014EE60(&it, func_0014EE70(self->list)->next);
    n = it;
    func_0014EE50(&end, func_0014EE70(self->list));
    while (n != end) {
        
        Dat_EE90* d = &n->d;
        if (bestPrio < d->prio) {
            bestPrio = d->prio;
            best = H_Get(&d->h);
        }
        n = n->next;
        func_0014EE50(&end, func_0014EE70(self->list));
    }
    return best;
}