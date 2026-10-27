#pragma cplusplus on
#include "types.h"
struct K1DE2D0 { unsigned char a; unsigned char b; };
struct N1DE2D0 { N1DE2D0* left; N1DE2D0* right; int pad[2]; K1DE2D0 key; };
struct T1DE2D0 { int count; N1DE2D0* root; };
struct I1DE2D0 { N1DE2D0* node; };
static inline bool K1DE2D0_less(const K1DE2D0& x, const K1DE2D0& y)
{
    return x.a < y.a || (x.a == y.a && x.b < y.b);
}
extern "C" void std_tree_pair_cWeaponSlotPair_value_compare_find(I1DE2D0* out, T1DE2D0* t, const K1DE2D0* k)
{
    N1DE2D0* x = t->root;
    N1DE2D0* y = (N1DE2D0*)&t->root;
    while (x) {
        if (!K1DE2D0_less(x->key, *k)) {
            y = x;
            x = x->left;
        } else
            x = x->right;
    }
    if (y == (N1DE2D0*)&t->root || K1DE2D0_less(*k, y->key))
        out->node = (N1DE2D0*)&t->root;
    else
        out->node = y;
}