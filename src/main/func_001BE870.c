#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_1BE870;
struct T_1BE870 { int count; N_1BE870* header; int pad8; N_1BE870* leftmost; };
extern "C" { void Tree_Successor(N_1BE870** it); void func_0013C800(N_1BE870* n, N_1BE870* header);
void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" { char D_0049ED08[] = "allocator.hh"; }
extern "C" void func_001BE870(T_1BE870* t, N_1BE870** it)
{
    N_1BE870* n = *it;
    N_1BE870** lm = &t->leftmost;
    if (n == t->leftmost) {
        Tree_Successor(it);
        *lm = *it;
    }
    func_0013C800(n, t->header);
    if (n) {
        AllocGuard guard;
        Mem_Free(0, n, D_0049ED08, 0x64);
    }
    t->count--;
}