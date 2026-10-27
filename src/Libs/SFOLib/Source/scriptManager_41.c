/*
 * Libs/SFOLib/Source/scriptManager: 1 file, 003E3160
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin scriptManager_3E3160 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_1BE870;
struct T_1BE870 { int count; N_1BE870* header; int pad8; N_1BE870* leftmost; };
extern "C" { void std_red_black_tree_1_increment(N_1BE870** it); void std_red_black_tree_1_balance_erase(N_1BE870* n, N_1BE870* header);
void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" { char D_004BDBF8[] = "allocator.hh"; }
extern "C" void std_tree_pair_int_value_compare_erase_tree_2(T_1BE870* t, N_1BE870** it)
{
    N_1BE870* n = *it;
    N_1BE870** lm = &t->leftmost;
    if (n == t->leftmost) {
        std_red_black_tree_1_increment(it);
        *lm = *it;
    }
    std_red_black_tree_1_balance_erase(n, t->header);
    if (n) {
        AllocGuard guard;
        cMemMan_Deallocate(0, n, D_004BDBF8, 0x64);
    }
    t->count--;
}
static inline void merge_flush_scriptManager_3E3160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end scriptManager_3E3160 */
