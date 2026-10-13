#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct V2CE070 { char pad[8]; char s8[0xC]; char s14[4]; };
struct N2CE070 { N2CE070* prev; N2CE070* next; V2CE070 val; };
struct It2CE070 { N2CE070* p; };
struct L2CE070 { int size; };
extern "C" {
extern char D_004AD158[];
void String_Dtor(void* p, int f);
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void VDtor2CE070(V2CE070* v)
{
    if (v) {
        if (v->s14)
            String_Dtor(v->s14, 0);
        if (v->s8)
            String_Dtor(v->s8, 0);
    }
}
extern "C" void func_002CE070(It2CE070* ret, L2CE070* l, It2CE070* pos)
{
    N2CE070* n = pos->p;
    pos->p = n->next;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    VDtor2CE070(&n->val);
    if (n) {
        AllocGuard g;
        Mem_Free(0, n, D_004AD158, 0x64);
    }
    l->size--;
    ret->p = pos->p;
}