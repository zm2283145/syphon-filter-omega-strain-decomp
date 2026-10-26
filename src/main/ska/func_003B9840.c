#include "types.h"
#pragma cplusplus on
#pragma opt_propagation off
#pragma opt_common_subs off
#include "tstr_types.h"

struct TV_3B9840 { __int128 q[3]; int w; };
struct TN_3B9840 { TN_3B9840* left; TN_3B9840* right; unsigned int parentAndColor; int pad; TV_3B9840 value; };
struct TT_3B9840 { unsigned int count; TN_3B9840* root; int pad; TN_3B9840* leftmost; };
extern "C" { extern char D_004BCEF0[]; }
extern "C" { char D_004BCF98[] = "allocator.hh"; }
extern "C" {
void std_red_black_tree_1_balance_insert(void* node, void* root);
}
/* 3-quad copy loop (hand-written in the original) */
static inline void Copy3(void* d0, const void* s0)
{
    int n = 3;
    __int128 t;
    const void* s = s0;
    void* d = d0;
    asm {
        .set noreorder
    loop:
        lq t, 0(s)
        addiu d, d, 16
        addi n, n, -1
        addiu s, s, 16
        bgtz n, loop
        sq t, -16(d)
        .set reorder
    }
}
/* with opt_propagation/opt_common_subs off, max_size() - 1 is computed at run time */
static inline unsigned int MaxSize() { unsigned int r; r = 0xFFFFFFFFU; return r; }
extern "C" TN_3B9840* std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_node_at_nodeP_bool_bool_pairR(TT_3B9840* tree, TN_3B9840* parent, int left, int first, const TV_3B9840* src)
{
    if (tree->count > MaxSize() - 1) {
        Libc_Fprintf(D_00489738->stream, D_004BCEF0);
        Libc_Abort();
    }
    TN_3B9840* node = (TN_3B9840*)TStr_Alloc(0x50, D_004BCF98, 0x5C);
    TV_3B9840* v = &node->value;
    if (v) {
        Copy3(v, src);
        v->w = src->w;
    }
    node->right = 0;
    node->left = 0;
    node->parentAndColor = (unsigned int)parent | (node->parentAndColor & 1);
    if (left)
        parent->left = node;
    else
        parent->right = node;
    tree->count++;
    std_red_black_tree_1_balance_insert(node, tree->root);
    if (first)
        tree->leftmost = node;
    return node;
}