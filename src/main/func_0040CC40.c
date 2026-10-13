#include "types.h"
#pragma cplusplus on
#include "tree_insert_unique_u32.h"

extern "C" {
static const unsigned int dat_00493C28[2] = { 0x1, 0x0 };
static const unsigned int dat_00493C30[4] = { 0x0, 0x0, 0x0, 0x0 };
TUNode* func_0040CFF0(TUTree* t, TUNode* parent, bool left, bool first,
                 const unsigned int* v);
}
extern "C" void ObjMap_Insert(TUPair* ret, TUTree* t, const unsigned int* v)
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
        ret->it = func_0040CFF0(t, parent, left, first, v);
        ret->ok = (*(bool*)dat_00493C28);
    } else {
        ret->it = y;
        ret->ok = (*(bool*)dat_00493C30);
    }
}
