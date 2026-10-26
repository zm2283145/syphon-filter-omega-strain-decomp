#pragma cplusplus on
#include "types.h"
struct K1DF650 { unsigned char a; unsigned char b; };
struct N1DF650 { N1DF650* left; N1DF650* right; int pad[2]; K1DF650 key; };
struct T1DF650 { int count; N1DF650* root; };
struct R1DF650 { N1DF650* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_0048A958[2] = { 0x1, 0x0 };
static const unsigned int dat_0048A960[2] = { 0 };
N1DF650* Tree_Insert_1DF7A0(T1DF650* t, N1DF650* parent, bool left, bool leftmost, const K1DF650* k); }
static inline bool K1DF650_less(const K1DF650& x, const K1DF650& y)
{
    return x.a < y.a || (x.a == y.a && x.b < y.b);
}
extern "C" void std_tree_pair_cWeaponSlotPair_value_compare_insert_one(R1DF650* out, T1DF650* t, const K1DF650* k)
{
    bool left = true;
    N1DF650* j = 0;
    N1DF650* x = t->root;
    N1DF650* y = (N1DF650*)&t->root;
    bool leftmost = true;
    while (x) {
        y = x;
        if (K1DF650_less(*k, x->key)) {
            x = x->left;
            left = true;
        } else {
            j = x;
            x = x->right;
            left = false;
            leftmost = false;
        }
    }
    if (j == 0 || K1DF650_less(j->key, *k)) {
        out->node = Tree_Insert_1DF7A0(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_0048A958);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_0048A960);
    }
}