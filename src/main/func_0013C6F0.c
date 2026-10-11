#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_C6F0 { void* l; void* r; int p; char val[4]; };
struct T_C6F0 { int count; void* root; int pad8; N_C6F0* head; };
extern "C" {
extern char D_0049ADD0[];
void Mem_Free(int pool, void* p, char* file, int line);
void Tree_Successor(N_C6F0** it);
void func_0013C800(N_C6F0* n, void* root);
void func_00138B70(void* v, short f);
}
extern "C" void func_0013C6F0(T_C6F0* t, N_C6F0** it)
{
    N_C6F0* n = *it;
    N_C6F0** hp = &t->head;
    if (n == t->head) {
        Tree_Successor(it);
        *hp = *it;
    }
    func_0013C800(n, t->root);
    if (n->val) {
        if (n->val)
            func_00138B70(n->val, 0);
    }
    if (n) {
        AllocGuard g;
        Mem_Free(0, n, D_0049ADD0, 0x64);
    }
    t->count--;
}