#include "types.h"
typedef struct N_CFF0 { struct N_CFF0* left; struct N_CFF0* right; unsigned int parent; } N_CFF0;
void func_0013CFF0(N_CFF0* x, N_CFF0** root)
{
    N_CFF0* y = x->left;
    N_CFF0* p;
    if (*root == x)
        *root = y;
    x->left = y->right;
    if (y->right)
        y->right->parent = (unsigned int)x | (y->right->parent & 1);
    y->parent = (x->parent & ~1) | (y->parent & 1);
    p = (N_CFF0*)(x->parent & ~1);
    if (x == p->left)
        p->left = y;
    else
        p->right = y;
    y->right = x;
    x->parent = (unsigned int)y | (x->parent & 1);
}