/*
 * SFOGame/Source/GameParticle: 1 file, 001C53C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin Loader_1C53C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tstr_types.h"
#pragma inline_depth(10)
struct PRVec_1C53C0 { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049AE50[];
}
#pragma opt_common_subs off
extern "C" void std_vector_pod_int_init_uintP_uintP_forwarditeratortag(PRVec_1C53C0* v, int* first, int* last)
{
    v->count = v->cap = last - first;
    if (v->count > 0x1800000) {
        Libc_Fprintf(D_00489738->stream, "vector length error\n");
        Libc_Abort();
    }
    unsigned int n = v->count;
    if (n) {
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * 4, D_0049AE50, 0x5C);
        int* s = first;
        int* d = v->data;
        while (s < last) {
            *d = *s;
            s++;
            d++;
        }
    }
}
static inline void merge_flush_Loader_1C53C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Loader_1C53C0 */
