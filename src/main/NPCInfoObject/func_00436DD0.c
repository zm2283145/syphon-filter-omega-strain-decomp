#include "types.h"
#pragma cplusplus on
#include "tree_insert_unique_u32.h"

extern "C" {
static const unsigned int dat_00494220[2] = { 0x1, 0x0 };
static const unsigned int dat_00494228[2] = { 0x0, 0x0 };
TUNode* func_00437180(TUTree* t, TUNode* parent, bool left, bool first,
                 const unsigned int* v);
}
extern "C" void func_00436DD0(TUPair* ret, TUTree* t, const unsigned int* v)
{
    bool left = true;
    bool first = left;
    TUNode* y = 0;
    TUNode* parent = (TUNode*)&t->root;
    TUNode* x = t->root;
    while (x) {
        parent = x;
        if (*v < x->key) {
            x = x->left;
            left = true;
        } else {
            y = x;
            x = x->right;
            left = false;
            first = false;
        }
    }
    if (!y || y->key < *v) {
        ret->it = func_00437180(t, parent, left, first, v);
        ret->ok = (*(bool*)dat_00494220);
    } else {
        ret->it = y;
        ret->ok = (*(bool*)dat_00494228);
    }
}
