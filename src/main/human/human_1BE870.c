/*
 * main/human: 2 files, 001BE870-001BE960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BE870 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_1BE870;
struct T_1BE870 { int count; N_1BE870* header; int pad8; N_1BE870* leftmost; };
extern "C" { void std_red_black_tree_1_increment(N_1BE870** it); void std_red_black_tree_1_balance_erase(N_1BE870* n, N_1BE870* header);
void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" { char D_0049ED08[] = "allocator.hh"; }
extern "C" void std_tree_pair_int_value_compare_erase_tree(T_1BE870* t, N_1BE870** it)
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
        cMemMan_Deallocate(0, n, D_0049ED08, 0x64);
    }
    t->count--;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BE870 */

/* merge_units: begin func_001BE960 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
struct RingE960 {
    int** cur; int** begin; int** x8; int** end;
};
struct DqItE960 { RingE960 ring; char* elem; char* bend; };
struct DqE960 { int capacity; int count; int size; int** data; unsigned int start; };
extern "C" void func_001BEAD0(RingE960* out, DqE960* arr);
extern "C" RingE960* func_001BEAA0(RingE960* d, RingE960* s);
extern "C" void func_001BE960(DqItE960* out, DqE960* dq, int n) {
    unsigned int idx = n + dq->start;
    RingE960 q;
    RingE960 it;
    RingE960 s;
    char* blk;
    func_001BEAD0(&s, dq);
    func_001BEAA0(&q, &s);
    it = q;
    RingE960* rp = &it;
    {
        int nn = idx >> 3;
        int size = it.end - it.begin;
        nn += it.cur - it.begin;
        if (nn < 0) nn += size;
        else if (nn >= size) nn -= size;
        rp->cur = rp->begin + nn;
    }
    int** c0 = rp->cur; int** c1 = rp->begin; int** c2 = rp->x8; int** c3 = rp->end;
    blk = dq->count == 0 ? 0 : (char*)*c0;
    out->ring.cur = c0; out->ring.begin = c1; out->ring.x8 = c2; out->ring.end = c3;
    out->elem = blk + (idx & 7) * 248;
    out->bend = blk + 0x7C0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BE960 */
