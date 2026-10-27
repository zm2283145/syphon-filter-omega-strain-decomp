/*
 * main/humanIk: range (5 files, 001DE5C0-001DEF90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_001DE5C0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
extern char D_004A0170[];
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
