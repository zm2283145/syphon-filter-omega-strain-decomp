#include "types.h"
typedef struct C3FtNode { struct C3FtNode* left; struct C3FtNode* right; int pad; int key; } C3FtNode;
typedef struct { int pad; C3FtNode* root; } C3FtTree;
extern C3FtNode* FrameTree_Insert(C3FtTree* t, C3FtNode* parent, unsigned char left, unsigned char leftmost, int* key);
void FrameTree_Find(C3FtNode** out, C3FtTree* t, int* key)
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
    *out = FrameTree_Insert(t, parent, left, leftmost, key);
}