#pragma cplusplus on
#include "types.h"
#include "tree_insert_obj.h"
struct Val_1C4F20 { int a, b, c; int d; };
extern "C" {
extern char D_0049F2E0[];
void std_basic_string_char_char_traits_char_ctor_basicstringR(void* d, const void* s);
void std_red_black_tree_1_balance_insert(void* node, void* root);
}
extern "C" TONode* std_tree_pair_cString_value_compare_insert_node_at_nodeP_bool_bool_pairR_2(TOTree* tree, TONode* parent, int left, int first, const Val_1C4F20* src)
{
    if (tree->count > 0xFFFFFFFFU - 1) {
        Libc_Fprintf(D_00489738->stream, D_0049F2E0);
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