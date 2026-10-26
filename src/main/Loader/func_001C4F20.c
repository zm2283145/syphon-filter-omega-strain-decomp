#pragma cplusplus on
#include "types.h"
#include "tree_insert_obj.h"
struct Val_1C4F20 { int a, b, c; int d; };
extern "C" {
extern char D_0049F2E0[];
void String_CopyCtor(void* d, const void* s);
void std_red_black_tree_1_balance_insert(void* node, void* root);
}
extern "C" TONode* Tree_Insert_1C4F20(TOTree* tree, TONode* parent, int left, int first, const Val_1C4F20* src)
{
    if (tree->count > 0xFFFFFFFFU - 1) {
        Libc_Fprintf(D_00489738->stream, D_0049F2E0);
        Libc_Abort();
    }
    TONode* node = (TONode*)TStr_Alloc(0x1C, "allocator.hh", 0x5C);
    Val_1C4F20* v = (Val_1C4F20*)node->value;
    if (v) {
        String_CopyCtor(v, src);
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