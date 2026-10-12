#pragma cplusplus on
#include "types.h"
struct K1C4770 { int w[4]; };
struct N1C4770 { N1C4770* left; N1C4770* right; int color; K1C4770 key; };
struct T1C4770 { int count; N1C4770* root; };
struct R1C4770 { N1C4770* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_00493C18[2] = { 0x1, 0x0 };
static const unsigned int dat_00493C20[2] = { 0 };
int func_0013C310(const K1C4770* a, const K1C4770* b);
N1C4770* func_0040B090(T1C4770* t, N1C4770* parent, bool left, bool leftmost, const K1C4770* k); }
static inline int K1C4770_less(const K1C4770* a, const K1C4770* b) { int r = func_0013C310(a, b) < 0; return r; }
extern "C" void func_0040A880(R1C4770* out, T1C4770* t, const K1C4770* k)
{
    N1C4770* j;
    N1C4770* y;
    N1C4770* x;
    bool left;
    bool leftmost;
    left = true;
    leftmost = left;
    j = 0;
    y = (N1C4770*)&t->root;
    x = t->root;

    while (x) {
        y = x;
        if (K1C4770_less(k, &x->key)) {
            x = x->left;
            left = true;
        } else {
            j = x;
            x = x->right;
            left = false;
            leftmost = false;
        }
    }
    if (j == 0 || K1C4770_less(&j->key, k)) {
        out->node = func_0040B090(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_00493C18);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_00493C20);
    }
}