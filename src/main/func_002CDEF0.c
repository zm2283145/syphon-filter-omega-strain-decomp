#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void String_Dtor(void* p, int flags);
extern char D_004AD158[];
}
struct V_DEF0 { char p0[8]; char a[0xC]; char b[0xC]; };
struct LN_DEF0 { LN_DEF0* prev; LN_DEF0* next; V_DEF0 val; };
struct L_DEF0 { int count; };
static inline void Dt_DEF0(V_DEF0* v)
{
    if (v) {
        if (v->b) String_Dtor(v->b, 0);
        if (v->a) String_Dtor(v->a, 0);
    }
}
/* Erases [first, last) from the list, destroying each value; returns last. */
extern "C" void func_002CDEF0(LN_DEF0** result, L_DEF0* list, LN_DEF0** first, LN_DEF0** last)
{
    LN_DEF0* f = *first;
    LN_DEF0* l = *last;
    if (f == l) {
        *result = l;
        return;
    }
    LN_DEF0* lp = l->prev;
    f->prev->next = lp->next;
    lp->next->prev = f->prev;
    while (*first != *last) {
        Dt_DEF0(&(*first)->val);
        LN_DEF0* n = *first;
        *first = (*first)->next;
        if (n) {
            AllocGuard guard;
            Mem_Free(0, n, D_004AD158, 0x64);
        }
        list->count--;
    }
    *result = *last;
}
