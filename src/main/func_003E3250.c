#include "types.h"
#pragma cplusplus on
#include "tree_insert_unique_kt.h"

struct func_003E3250_N { func_003E3250_N* left; func_003E3250_N* right; unsigned int parentAndColor; int key; };
struct func_003E3250_T { unsigned int count; func_003E3250_N* root; };
struct func_003E3250_P { func_003E3250_N* it; bool ok; };
extern "C" {
static const unsigned int dat_00493900[2] = { 0x1, 0x0 };
static const unsigned int dat_00493908[2] = { 0x0, 0x0 };
func_003E3250_N* func_003E3DF0(func_003E3250_T* t, func_003E3250_N* parent, bool left, bool first,
                 const int* v);
}
extern "C" void func_003E3250(func_003E3250_P* ret, func_003E3250_T* t, const int* v)
{
    bool left = true;
    bool first = left;
    func_003E3250_N* y = 0;
    func_003E3250_N* parent = (func_003E3250_N*)&t->root;
    func_003E3250_N* x = t->root;
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
        ret->it = func_003E3DF0(t, parent, left, first, v);
        ret->ok = (*(bool*)dat_00493900);
    } else {
        ret->it = y;
        ret->ok = (*(bool*)dat_00493908);
    }
}
