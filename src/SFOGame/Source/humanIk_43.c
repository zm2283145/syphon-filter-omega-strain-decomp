/*
 * SFOGame/Source/humanIk: 7 files, 001DE2D0-001DE5C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001DE2D0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_001DE2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DE2D0 */

/* merge_units: begin func_001DE3B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* ReorderList_uint_cQuaternionP_uintP: reorder 16-byte elements in place by an order table (same family as ReorderList_uint_cJointLimitsP_uintP) */
extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
int cMemMan_Deallocate(int, void*, char*, int);
extern char D_004A0170[];
}
template <class T> static inline void Swap1DE3B0(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
struct Q1DE3B0 {
    float x, y, z, w;
    Q1DE3B0() {}
    // 128-bit lq/sq quadword copy idiom
    Q1DE3B0(const Q1DE3B0& o) { Q1DE3B0* d = this; const Q1DE3B0* s = &o; __int128 t; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    // 128-bit lq/sq quadword copy idiom
    Q1DE3B0& operator=(const Q1DE3B0& o) { Q1DE3B0* d = this; const Q1DE3B0* s = &o; __int128 t; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" void ReorderList_uint_cQuaternionP_uintP(unsigned int n, Q1DE3B0* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)cMemMan_Allocate(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE3B0(data[k], data[j]);
        Swap1DE3B0(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        cMemMan_Deallocate(0, tmp, D_004A0170, 0x7C3);
    }
}
static inline void merge_flush_func_001DE3B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DE3B0 */

/* merge_units: begin func_001DE5C0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on

extern "C" {
}

template <class T> static inline void Swap1DE5C0(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
struct V3 { float v[3]; float w; V3(const V3& o) { for (int i = 0; i < 3; i++) v[i] = o.v[i]; } V3& operator=(const V3& o) { v[0] = o.v[0]; v[1] = o.v[1]; v[2] = o.v[2]; return *this; } };

extern "C" void ReorderList_uint_cJointLimitsP_uintP(unsigned int n, V3* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)cMemMan_Allocate(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE5C0(data[k], data[j]);
        Swap1DE5C0(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        cMemMan_Deallocate(0, tmp, D_004A0170, 0x7C3);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DE5C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DE5C0 */

/* merge_units: begin func_001DE870 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
}

template <class T> static inline void Swap1DE870(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

extern "C" void ReorderList_uint_floatP_uintP(unsigned int n, float* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)cMemMan_Allocate(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE870(data[k], data[j]);
        Swap1DE870(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        cMemMan_Deallocate(0, tmp, D_004A0170, 0x7C3);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DE870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DE870 */

/* merge_units: begin func_001DEAD0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
}

extern "C" void ReorderList_uint_boolP_uintP(unsigned int n, unsigned char* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)cMemMan_Allocate(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE870(data[k], data[j]);
        Swap1DE870(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        cMemMan_Deallocate(0, tmp, D_004A0170, 0x7C3);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DEAD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DEAD0 */

/* merge_units: begin func_001DED30 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
}

/* 1-byte signed enum: a plain char element allocates the swap temp differently */
#pragma enumsalwaysint off
enum E1DED30 { E1DED30_m = -1, E1DED30_p = 1 };
extern "C" void ReorderList_uint_eAnimSourceP_uintP(unsigned int n, E1DED30* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)cMemMan_Allocate(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE870(data[k], data[j]);
        Swap1DE870(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        cMemMan_Deallocate(0, tmp, D_004A0170, 0x7C3);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DED30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DED30 */

/* merge_units: begin func_001DEF90 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
}

/* 1-byte signed enum: a plain char element allocates the swap temp differently */
#pragma enumsalwaysint off
enum E1DEF90 { E1DEF90_m = -1, E1DEF90_p = 1 };
extern "C" void ReorderList_uint_eAnimSourceP_uintP_2(unsigned int n, E1DEF90* data, unsigned int* order)
{
    unsigned int* tmp;
    unsigned int i;
    unsigned int k;
    unsigned int j;
    {
        AllocGuard g;
        tmp = (unsigned int*)cMemMan_Allocate(0, n * 4, D_004A0170, 0x7AF);
    }
    for (i = 0; i < n; i++)
        tmp[i] = order[i];
    for (k = 0; k < n; k++) {
        for (j = 0; j < n && tmp[j] != k; j++)
            ;
        Swap1DE870(data[k], data[j]);
        Swap1DE870(tmp[k], tmp[j]);
    }
    {
        AllocGuard g;
        cMemMan_Deallocate(0, tmp, D_004A0170, 0x7C3);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DEF90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DEF90 */
