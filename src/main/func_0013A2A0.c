#include "types.h"
typedef struct C6Node_13A2A0 { struct C6Node_13A2A0* left; struct C6Node_13A2A0* right; unsigned int parent; } C6Node_13A2A0;
#define C6_PARENT(n) ((C6Node_13A2A0*)((n)->parent & ~1))
void Tree_Successor(C6Node_13A2A0** it) {
    C6Node_13A2A0* n = (*it)->right;
    C6Node_13A2A0* p;
    if (n) {
        C6Node_13A2A0* l = n->left;
        while (l) { n = l; l = l->left; }
        *it = n;
        return;
    }
    while (*it != (p = C6_PARENT(*it))->left) *it = p;
    *it = p;
}