/*
 * main/game: 4 files, 0013A1B0-0013A320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013A1B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" void Mem_Free(int pool, void* allocation, char* file, int line);
struct Elem_A1B0 { char pad[0x20]; char live; };
extern "C" void opDelete_cLosRequestP_int_bool_charP_etc(Elem_A1B0* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            allocation->live = 0;
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_0013A1B0 */

/* merge_units: begin func_0013A290 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* clear(): count = 0. */
void Hud_ClearPda(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013A290 */

/* merge_units: begin func_0013A2A0 */
#pragma push /* merge_units */
typedef struct C6Node_13A2A0 { struct C6Node_13A2A0* left; struct C6Node_13A2A0* right; unsigned int parent; } C6Node_13A2A0;
#define C6_PARENT(n) ((C6Node_13A2A0*)((n)->parent & ~1))
void Tree_Successor(C6Node_13A2A0** it) {
    C6Node_13A2A0* n = (*it)->right;
    C6Node_13A2A0* p;
    if (n) {
        C6Node_13A2A0* l = n->left;
        while (l) { n = l; l = l->left; }
        *it = n;
        return;
    }
    while (*it != (p = C6_PARENT(*it))->left) *it = p;
    *it = p;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013A2A0 */

/* merge_units: begin func_0013A320 */
#pragma push /* merge_units */
#pragma cplusplus on
struct N_0013C030 { N_0013C030* left; N_0013C030* right; int f8; char val[4]; };
extern "C" {
void String_Dtor(void* p, short f);
#if 0 /* merge_units */
void Mem_Free(int pool, void* p, const char* file, int line);
#endif /* merge_units */
#define Mem_Free(a0, a1, a2, a3) ((void)Mem_Free((a0), (a1), (char *)(a2), (a3))) /* merge_units */

}
extern "C" void std_tree_pair_cString_value_compare_destroy_nodeP(void* t, N_0013C030* n)
{
    if (n->left) std_tree_pair_cString_value_compare_destroy_nodeP(t, n->left);
    if (n->right) std_tree_pair_cString_value_compare_destroy_nodeP(t, n->right);
    if (n->val) { if (n->val) String_Dtor(n->val, 0); }
    if (n) {
        AllocGuard g;
        Mem_Free(0, n, "allocator.hh", 0x64);
    }
}
#undef Mem_Free /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013A320 */
