#include "types.h"
typedef struct N_CF60 { struct N_CF60* left; struct N_CF60* right; unsigned int parent; } N_CF60;
void func_0013CF60(N_CF60* x, N_CF60** root)
{
    N_CF60* y = x->right;
    N_CF60* p;
    if (*root == x)
        *root = y;
    x->right = y->left;
    if (y->left)
        y->left->parent = (unsigned int)x | (y->left->parent & 1);
    y->parent = (x->parent & ~1) | (y->parent & 1);
    p = (N_CF60*)(x->parent & ~1);
    if (x == p->left)
        p->left = y;
    else
        p->right = y;
    y->left = x;
    x->parent = (unsigned int)y | (x->parent & 1);
}