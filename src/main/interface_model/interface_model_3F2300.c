/*
 * main/interface_model: range (2 files, 003F2300-003F24A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tstr_types.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_insert_fill_cse.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
void *memcpy();

/* merge_units: begin func_003F2300 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)

struct BVec_3F2300 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
char D_004BE100[] = "vector::reserve length error\n";
extern char D_004BE180[];
extern char D_004BE190[];
}
static inline void Free_3F2300(char* p) { if (p) TStr_Free(p, D_004BE190, 0x64); }
extern "C" void std_vector_pod_AnimType_reserve(BVec_3F2300* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x6000000) {
            Libc_Fprintf(D_00489738->stream, D_004BE100);
            Libc_Abort();
        }
        char* old = v->data;
        char** pdata = &v->data;
        *pdata = TStr_Alloc(n, D_004BE180, 0x5C);
        if (old) {
            memcpy(v->data, old, *(volatile unsigned int*)&v->count);
            Free_3F2300(old);
        }
        v->cap = n;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F2300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F2300 */

/* merge_units: begin func_003F24A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define VIFC_ASSIGN(d, s) ((d)->x = (s)->x, (d)->y = (s)->y)
#define VIFC_COPY(d, s) ((d)->x = (s)->x, (d)->y = (s)->y)
struct E_003F24A0 { float x, y; };
DEFINE_VECTOR_INSERT_FILL_CSE(func_003F24A0, E_003F24A0, 0xC00000, 0x600000, D_004BE0E0, D_004BE170, 0x5C, std_swap_vectordeleterR_vectordeleterR_43, extern char D_004BE140[]; void func_003F4390(func_003F24A0_V* v);, func_003F4390(&tmp); { E_003F24A0* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004BE140, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003F24A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003F24A0 */
