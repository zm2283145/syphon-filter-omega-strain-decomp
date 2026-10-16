/*
 * main/materialProperties: 5 files, 0040A6F0-0040A9A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040A6F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_004088D0(void* self, short flags);
void func_0040A6F0(void* allocation, int pool, int destroy, char* file, int line);
}
void func_0040A6F0(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            func_004088D0((char*)allocation + 12, -1);
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040A6F0 */

/* merge_units: begin func_0040A7D0 */
#pragma push /* merge_units */
extern char D_004BEC78[];
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int del);
#if 0 /* merge_units */
extern void Mem_Free(int heap, void* p, const char* file, int line);
#endif /* merge_units */
#define Mem_Free(a0, a1, a2, a3) (Mem_Free((a0), (a1), (char *)(a2), (a3))) /* merge_units */

void func_0040A7D0(void* self, void* p)
{
    if (p) {
        int g[1];
        func_00136DA0(g);
        Mem_Free(0, p, D_004BEC78, 100);
        func_0012F530(g, -1);
    }
}
#undef Mem_Free /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040A7D0 */

/* merge_units: begin func_0040A830 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int func_00138350(void* obj, int flags);

void* func_0040A830(char* self) {
    return self + 4;
}

/* Destroys obj (flags -1) when it is non-null. */
void func_0040A840(void* self, void* obj) {
    if (obj != 0) {
        func_00138350(obj, -1);
    }
}

void* func_0040A870(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040A830 */

/* merge_units: begin func_0040A880 */
#pragma push /* merge_units */
#pragma cplusplus on
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
#pragma pop /* merge_units */
/* merge_units: end func_0040A880 */

/* merge_units: begin func_0040A9A0 */
#pragma push /* merge_units */
Map* func_0040A9A0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040A9A0 */
