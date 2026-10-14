/*
 * main/guiManager: 5 files, 00419B80-00419E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00419B80 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_00418720(void* self, short flags);
void func_00419B80(void* allocation, int pool, int destroy, char* file, int line);
}
void func_00419B80(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            func_00418720((char*)allocation + 12, -1);
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_00419B80 */

/* merge_units: begin func_00419C60 */
#pragma push /* merge_units */
extern char D_004BF180[];
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int del);
#if 0 /* merge_units */
extern void Mem_Free(int heap, void* p, const char* file, int line);
#endif /* merge_units */
#define Mem_Free(a0, a1, a2, a3) (Mem_Free((a0), (a1), (char *)(a2), (a3))) /* merge_units */

void func_00419C60(void* self, void* p)
{
    if (p) {
        int g[1];
        func_00136DA0(g);
        Mem_Free(0, p, D_004BF180, 100);
        func_0012F530(g, -1);
    }
}
#undef Mem_Free /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00419C60 */

/* merge_units: begin func_00419CC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int func_00138350(void* obj, int flags);

void* func_00419CC0(char* self) {
    return self + 4;
}

/* Destroys obj (flags -1) when it is non-null. */
void func_00419CD0(void* self, void* obj) {
    if (obj != 0) {
        func_00138350(obj, -1);
    }
}

void* func_00419D00(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00419CC0 */

/* merge_units: begin func_00419D10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct K1C4770 { int w[4]; };
struct N1C4770 { N1C4770* left; N1C4770* right; int color; K1C4770 key; };
struct T1C4770 { int count; N1C4770* root; };
struct R1C4770 { N1C4770* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_004940F0[2] = { 0x1, 0x0 };
static const unsigned int dat_004940F8[2] = { 0 };
int func_0013C310(const K1C4770* a, const K1C4770* b);
N1C4770* func_00419E50(T1C4770* t, N1C4770* parent, bool left, bool leftmost, const K1C4770* k); }
static inline int K1C4770_less(const K1C4770* a, const K1C4770* b) { int r = func_0013C310(a, b) < 0; return r; }
extern "C" void func_00419D10(R1C4770* out, T1C4770* t, const K1C4770* k)
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
        out->node = func_00419E50(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_004940F0);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_004940F8);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00419D10 */

/* merge_units: begin func_00419E30 */
#pragma push /* merge_units */
Map* func_00419E30(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_00419E30 */
