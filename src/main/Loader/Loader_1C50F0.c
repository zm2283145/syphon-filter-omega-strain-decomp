/*
 * main/Loader: 2 files, 001C50F0-001C5370
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C50F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tstr_types.h"
#pragma inline_depth(10)
struct PRVec_1C50F0 { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049AE50[];
extern char D_0049AF00[];
extern char D_0049F300[];
}
static inline void PRVec_1C50F0_Free(int* p)
{
    if (p)
        TStr_Free((char*)p, D_0049AF00, 0x64);
}
#pragma opt_common_subs off
extern "C" void std_vector_pod_int_do_assign(PRVec_1C50F0* v, int* first, int* last)
{
    unsigned int n = last - first;
    if (v->cap < n) {
        if (n > 0x1800000) {
            Libc_Fprintf(D_00489738->stream, D_0049F300);
            Libc_Abort();
        }
        v->count = 0;
        int* old = v->data;
        if (old) {
            PRVec_1C50F0_Free(old);
            v->data = 0;
            v->cap = 0;
        }
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * 4, D_0049AE50, 0x5C);
        v->cap = n;
    }
    int* d = v->data;
    int* s = first;
    while (s < last) {
        *d = *s;
        s++;
        d++;
    }
    v->count = n;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C50F0 */

/* merge_units: begin func_001C5370 */
#pragma push /* merge_units */
typedef struct { char unused; } Alloc;
typedef struct { int* begin; int* end; int* cap; } IntVec;
extern void std_vector_pod_int_init_uintP_uintP_forwarditeratortag(IntVec* v, int* first, int* last, Alloc alloc);
/* Constructs a vector as a copy of the range held by src. */
IntVec* std_vector_pod_int_ctor(IntVec* v, PtrVec* src)
{
    Alloc alloc;
    v->begin = 0;
    v->end = 0;
    v->cap = 0;
    std_vector_pod_int_init_uintP_uintP_forwarditeratortag(v, src->data, src->data + src->count, alloc);
    return v;
}
#pragma pop /* merge_units */
/* merge_units: end func_001C5370 */
