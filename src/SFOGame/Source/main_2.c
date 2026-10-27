/*
 * main/game: 2 files, 0013C570-0013C6F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013C570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tree_insert_obj.h"
struct Val_1C4F20 { int a, b, c; int d; };
extern "C" {
void std_basic_string_char_char_traits_char_ctor_basicstringR(void* d, const void* s);
void std_red_black_tree_1_balance_insert(void* node, void* root);
}
extern "C" TONode* std_tree_pair_cString_value_compare_insert_node_at_nodeP_bool_bool_pairR(TOTree* tree, TONode* parent, int left, int first, const Val_1C4F20* src)
{
    if (tree->count > 0xFFFFFFFFU - 1) {
        Libc_Fprintf(D_00489738->stream, "tree::insert length error\n");
        Libc_Abort();
    }
    TONode* node = (TONode*)TStr_Alloc(0x1C, "allocator.hh", 0x5C);
    Val_1C4F20* v = (Val_1C4F20*)node->value;
    if (v) {
        std_basic_string_char_char_traits_char_ctor_basicstringR(v, src);
        v->d = src->d;
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
#pragma pop /* merge_units */
/* merge_units: end func_0013C570 */

/* merge_units: begin func_0013C6F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct N_C6F0 { void* l; void* r; int p; char val[4]; };
struct T_C6F0 { int count; void* root; int pad8; N_C6F0* head; };
extern "C" {
extern char D_0049ADD0[];
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void std_red_black_tree_1_increment(N_C6F0** it);
void std_red_black_tree_1_balance_erase(N_C6F0* n, void* root);
void String_Dtor(void* v, short f);
}
extern "C" void std_tree_pair_cString_value_compare_erase(T_C6F0* t, N_C6F0** it)
{
    N_C6F0* n = *it;
    N_C6F0** hp = &t->head;
    if (n == t->head) {
        std_red_black_tree_1_increment(it);
        *hp = *it;
    }
    std_red_black_tree_1_balance_erase(n, t->root);
    if (n->val) {
        if (n->val)
            String_Dtor(n->val, 0);
    }
    if (n) {
        AllocGuard g;
        cMemMan_Deallocate(0, n, D_0049ADD0, 0x64);
    }
    t->count--;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013C6F0 */
