/*
 * Libs/SFOLib/Source/scriptBase: 2 files, 003D9470-003D95D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D9470 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#include "tstr_types.h"

struct V3_9470 { float x, y, z; };
struct Vec_9470 { unsigned int cap; unsigned int count; V3_9470* data; };

extern "C" {
extern char D_004BD3E0[];
extern char D_004BD408[];
}

extern "C" void std_vector_imp_EnumField_init(Vec_9470* v, unsigned int n, const V3_9470* val)
{
    if (n) {
        if (n > 0x800000) {
            Libc_Fprintf(D_00489738->stream, D_004BD3E0);
            Libc_Abort();
        }
        V3_9470** pdata = &v->data;
        *pdata = (V3_9470*)TStr_Alloc(n * sizeof(V3_9470), D_004BD408, 0x5C);
        v->cap = n;
        V3_9470* end = v->data + n;
        V3_9470* p = v->data;
        for (; p < end; p++) {
            if (p) {
                float x;
                float y;
                float z;
                x = val->x;
                y = val->y;
                z = val->z;
                p->x = x;
                p->y = y;
                p->z = z;
            }
            v->count++;
        }
    }
}
static inline void merge_flush_func_003D9470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D9470 */

/* merge_units: begin func_003D95D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" { char D_004BD3F8[] = "allocator.hh"; }
DEFINE_GUARDED_BUFFER_CALL_DTOR(std_vector_deleter_EnumField_dtor, std_vector_deleter_EnumField_clear, D_004BD3F8)
static inline void merge_flush_func_003D95D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D95D0 */
