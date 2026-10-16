#include "types.h"
/* float-keyed tree: find insert position, then insert via func_0013F820 */
typedef struct C3FtNode { struct C3FtNode* left; struct C3FtNode* right; int pad; float key; } C3FtNode;
typedef struct { int pad; C3FtNode* root; } C3FtTree;
extern C3FtNode* func_0013F820(C3FtTree* t, C3FtNode* parent, unsigned char left, unsigned char leftmost, float* key);
void SceneDrawMap_Insert(C3FtNode** out, C3FtTree* t, float* key)
{
    C3FtNode* parent = (C3FtNode*)&t->root;
    C3FtNode* n = t->root;
    unsigned char left = 1;
    unsigned char leftmost = left;
    while (n != 0) {
        parent = n;
        if (*key < n->key) {
            n = n->left;
            left = 1;
        } else {
            n = n->right;
            left = 0;
            leftmost = 0;
        }
    }
    *out = func_0013F820(t, parent, left, leftmost, key);
}