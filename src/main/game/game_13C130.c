/*
 * main/game: 3 files, 0013C130-0013C270
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013C130 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct K1C4770 { int w[4]; };
struct N1C4770 { N1C4770* left; N1C4770* right; int color; K1C4770 key; };
struct T1C4770 { int count; N1C4770* root; };
struct R1C4770 { N1C4770* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_00489BF8[2] = { 0x1, 0x0 };
static const unsigned int dat_00489C00[2] = { 0 };
int func_0013C310(const K1C4770* a, const K1C4770* b);
N1C4770* func_0013C570(T1C4770* t, N1C4770* parent, bool left, bool leftmost, const K1C4770* k); }
static inline int K1C4770_less(const K1C4770* a, const K1C4770* b) { int r = func_0013C310(a, b) < 0; return r; }
extern "C" void func_0013C130(R1C4770* out, T1C4770* t, const K1C4770* k)
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
        out->node = func_0013C570(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_00489BF8);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_00489C00);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0013C130 */

/* merge_units: begin func_0013C250 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Map* func_0013C250(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013C250 */

/* merge_units: begin func_0013C270 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
struct It_0013C270 { void* n; };
static inline int ItEq(void* a, It_0013C270* b) { return a == b->n; }
extern "C" { void func_0013C4A0(It_0013C270* r, void* t, int k); void func_0013C300(It_0013C270* r, void* t);
void func_0013C2F0(It_0013C270* r, It_0013C270* s); void func_0013C6F0(void* t, It_0013C270* it); }
extern "C" void func_0013C270(void* t, int k)
{
    It_0013C270 c;
    It_0013C270 a;
    It_0013C270 x;
    It_0013C270 e;
    void* n;
    func_0013C4A0(&a, t, k);
    n = a.n;
    func_0013C300(&e, t);
    func_0013C2F0(&c, &e);
    if (ItEq(n, &c) ^ 1) {
        x.n = n;
        func_0013C6F0(t, &x);
    }
}
#pragma bool reset
#pragma pop /* merge_units */
/* merge_units: end func_0013C270 */
