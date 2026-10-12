#pragma cplusplus on
#include "types.h"
#include "tree_insert_obj.h"
struct Val_1C4F20 { int a, b, c; int d; };
extern "C" {
extern char D_0049ADA0[];
void func_0013BCB0(void* d, const void* s);
void func_0013CD40(void* node, void* root);
}
extern "C" TONode* func_0013C570(TOTree* tree, TONode* parent, int left, int first, const Val_1C4F20* src)
{
    if (tree->count > 0xFFFFFFFFU - 1) {
        func_00123BE8(D_00489738->stream, D_0049ADA0);
        func_00121B60();
    }
    TONode* node = (TONode*)TStr_Alloc(0x1C, "allocator.hh", 0x5C);
    Val_1C4F20* v = (Val_1C4F20*)node->value;
    if (v) {
        func_0013BCB0(v, src);
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
    func_0013CD40(node, tree->root);
    if (first)
        tree->leftmost = node;
    return node;
}