#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_1BE870;
struct T_1BE870 { int count; N_1BE870* header; int pad8; N_1BE870* leftmost; };
extern "C" { void Tree_Successor(N_1BE870** it); void std_red_black_tree_1_balance_erase(N_1BE870* n, N_1BE870* header);
void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" { char D_004BDBF8[] = "allocator.hh"; }
extern "C" void std_tree_pair_int_value_compare_erase_tree_2(T_1BE870* t, N_1BE870** it)
{
    N_1BE870* n = *it;
    N_1BE870** lm = &t->leftmost;
    if (n == t->leftmost) {
        Tree_Successor(it);
        *lm = *it;
    }
    std_red_black_tree_1_balance_erase(n, t->header);
    if (n) {
        AllocGuard guard;
        Mem_Free(0, n, D_004BDBF8, 0x64);
    }
    t->count--;
}