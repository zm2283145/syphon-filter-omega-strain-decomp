#include "types.h"
#pragma bool off
typedef struct { char pad[0x10]; void* event; } SchNode_c7;
typedef struct { SchNode_c7* p; } SchIt_c7;
extern char D_0055A0F0[];
extern void func_003DFBF0(SchIt_c7* out, void* map);
extern void func_003DFAF0(SchIt_c7* out, void* map);
extern SchIt_c7* func_003DFAE0(SchIt_c7* dst, SchIt_c7* src);
extern void EventQueue_Remove(void* ev);
extern void Tree_Successor(SchIt_c7* it);
extern void func_003E3160(void* map, SchIt_c7* it);
static inline int IsZero_c7(int x) { return x == 0; }
static inline int ItNe_c7(SchIt_c7* a, SchIt_c7* b) { return (a->p == b->p) ^ 1; }
void Script_ClearSchedules_3DFB20(void) {
    SchIt_c7 it;
    SchIt_c7 end;
    SchIt_c7 b;
    SchIt_c7 tmp;
    SchIt_c7 e;
    func_003DFBF0(&b, D_0055A0F0);
    it.p = b.p;
    while (func_003DFAF0(&e, D_0055A0F0), func_003DFAE0(&end, &e), ItNe_c7(&it, &end)) {
        SchNode_c7* old;
        EventQueue_Remove(it.p->event);
        old = it.p;
        Tree_Successor(&it);
        tmp.p = old;
        func_003E3160(D_0055A0F0, &tmp);
    }
}