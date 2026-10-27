/*
 * SFOGame/Source/terrain: 2 files, 001748F0-00174A20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001748F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_reserve.h"
extern "C" { extern char D_0049CA60[]; extern char D_0049AE50[]; }

extern "C" void std_vector_pod_int_init_uint_uintR(PRVec* v, unsigned int n, const int* val)
{
    if (n) {
        if (n > 0x1800000) {
            Libc_Fprintf(D_00489738->stream, D_0049CA60);
            Libc_Abort();
        }
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * 4, D_0049AE50, 0x5C);
        v->count = n;
        v->cap = n;
        int* d = v->data;
        while (n) {
            *d = *val;
            n--;
            d++;
        }
    }
}
static inline void merge_flush_func_001748F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001748F0 */

/* merge_units: begin func_00174A20 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct V_00174A20 { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049CAD8[];
}

extern "C" void std_vector_imp_cObjectId_init(V_00174A20* v, unsigned int n, const int* val)
{
    if (n) {
        if (n > 0x1800000) {
            Libc_Fprintf(D_00489738->stream, D_0049CA60);
            Libc_Abort();
        }
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * sizeof(int), D_0049CAD8, 0x5C);
        v->cap = n;
        int* end;
        int* p;
        p = v->data;
        end = p + n;
        while (p < end) {
            if (p)
                *p = *val;
            p++;
            v->count++;
        }
    }
}
static inline void merge_flush_func_00174A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00174A20 */
