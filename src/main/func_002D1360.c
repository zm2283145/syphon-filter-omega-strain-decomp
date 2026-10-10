#include "types.h"
typedef struct { int key; int recv; int id; unsigned char flag; int a; int b; } C3NrPair;
typedef struct C3NrNode { struct C3NrNode* left; struct C3NrNode* right; int pad; C3NrPair v; } C3NrNode;
typedef struct { int pad; C3NrNode* root; } C3NrMap;
extern C3NrNode* func_002D1430(C3NrMap* m, C3NrNode* parent, unsigned char left, unsigned char leftmost, C3NrPair* v);
C3NrPair* NetRecvMap_Insert(C3NrMap* m, int* key)
{
    C3NrNode* cand = 0;
    C3NrNode* parent = (C3NrNode*)&m->root;
    C3NrNode* x = m->root;
    unsigned char left = 1;
    unsigned char leftmost = left;
    while (x != 0) {
        parent = x;
        if (*key < x->v.key) {
            x = x->left;
            left = 1;
        } else {
            cand = x;
            x = x->right;
            left = 0;
            leftmost = 0;
        }
    }
    if (cand == 0 || cand->v.key < *key) {
        C3NrPair p;
        p.key = *key;
        p.recv = 0;
        p.id = -1;
        p.flag = 0;
        p.a = 0;
        p.b = 0;
        return &func_002D1430(m, parent, left, leftmost, &p)->v;
    }
    return &cand->v;
}