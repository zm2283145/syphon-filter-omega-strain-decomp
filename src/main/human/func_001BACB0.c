#include "types.h"
#pragma cplusplus on
typedef struct C3TcNode { struct C3TcNode* left; struct C3TcNode* right; int pad[2]; char name[0x30]; } C3TcNode;
typedef struct { int pad; C3TcNode* root; } C3TcTree;
extern "C" int Name_Compare48(const char* a, const char* b, int n);
static inline bool C3TcLess(const char* a, const char* b)
{
    return !(a[0] == 0 && b[0] == 0) && Name_Compare48(a, b, 0x30) < 0;
}
extern "C" void Tree_Compare(C3TcNode** out, C3TcTree* t, const char* name)
{
    C3TcNode* x = t->root;
    C3TcNode* y = (C3TcNode*)&t->root;
    while (x != 0) {
        if (!C3TcLess(x->name, name)) {
            y = x;
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y == (C3TcNode*)&t->root || C3TcLess(name, y->name)) {
        *out = (C3TcNode*)&t->root;
    } else {
        *out = y;
    }
}