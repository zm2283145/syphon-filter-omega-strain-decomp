#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { int key; int val; int x8; } Ent_B060;
typedef struct N_B060 { struct N_B060* prev; struct N_B060* next; Ent_B060* e; } N_B060;
typedef struct { int a; int b; } It2_B060;
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_0049B670[];
extern char D_004EA1B0[];
void List_Begin(N_B060** out, void* list);
void func_0015AD60(N_B060** out, N_B060** in);
void func_0015AD50(N_B060** out, void* list);
void func_0015AD40(N_B060** out, N_B060** in);
void func_0015B1F0(void* list, Ent_B060** e);
}
typedef struct { char pad[0xC]; int id; } Ctl_B060;
typedef struct { char pad[0x30]; Ctl_B060* ctl; } NPC_B060;
static inline void Begin(N_B060** out) { N_B060* t; List_Begin(&t, D_004EA1B0); func_0015AD60(out, &t); }
static inline N_B060* End(N_B060** out) { N_B060* t; func_0015AD50(&t, D_004EA1B0); func_0015AD40(out, &t); return *out; }
static inline void Ent_Init(Ent_B060* p, Ctl_B060* c) { p->key = -1; p->key = c->id; p->val = 0; p->x8 = 0; }
extern "C" void NpcAi_GetPlayerRecord(NPC_B060* self, int bit, int set)
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
            p = (Ent_B060*)Mem_Alloc(0, 0xC, D_0049B670, 0xD7);
        }
        if (p)
            Ent_Init(p, self->ctl);
        found = p;
        func_0015B1F0(D_004EA1B0, &found);
    }
    if (set) {
        if (bit >= 0)
            found->val |= 1 << bit;
        else
            found->val = 0xFF;
    } else {
        if (bit >= 0)
            found->val &= ~(1 << bit);
        else
            found->val = 0;
    }
}