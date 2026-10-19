/*
 * main/GuiMissionStatList: 3 files, 00352020-003521A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00352020 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "owned_buffer8_dtor_deep.h"

DEFINE_OWNED_BUFFER8_DTOR_DEEP(func_00352020, D_004BACB8)
#pragma pop /* merge_units */
/* merge_units: end func_00352020 */

/* merge_units: begin func_00352110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_copy_ctor.h"

/* Copy-construct a string. */
DEFINE_SHORT_STRING_COPY_CTOR(func_00352110)
#pragma pop /* merge_units */
/* merge_units: end func_00352110 */

/* merge_units: begin func_003521A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
struct V3521A0 { unsigned int cap; unsigned int count; VRElem20* data; };
extern "C" {
extern char D_004BABF0[];
void* Mem_PlacementNew(unsigned int size, void* p);
void func_00352320(void* dst, const VRElem20* src);
}
extern "C" void func_003521A0(V3521A0* v, const VRElem20* first, const VRElem20* last)
{
    unsigned int n = last - first;
    if (v->count > 0x4CCCCC) {
        Libc_Fprintf(D_00489738->stream, D_004BABF0);
        Libc_Abort();
    }
    if (n) {
        VRElem20** pdata = &v->data;
        *pdata = (VRElem20*)TStr_Alloc(n * sizeof(VRElem20), "allocator.hh", 0x5C);
        v->cap = n;
        VRElem20* p = v->data;
        for (; first != last; first++, p++) {
            void* o = Mem_PlacementNew(sizeof(VRElem20), p);
            if (o) func_00352320(o, first);
            v->count++;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003521A0 */
