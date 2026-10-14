/*
 * main/ska: range (2 files, 003B6F80-003B7100)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tstr_types.h"
#pragma pop

/* merge_units: begin func_003B6F80 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
struct V3B6F80 { unsigned int cap; unsigned int count; VRElem20* data; };
extern "C" {
extern char D_004A3F20[];
void* func_00139BC0(unsigned int size, void* p);
void func_0020C020(void* dst, const VRElem20* src);
}
extern "C" void func_003B6F80(V3B6F80* v, const VRElem20* first, const VRElem20* last)
{
    unsigned int n = last - first;
    if (v->count > 0x4CCCCC) {
        func_00123BE8(D_00489738->stream, "vector length error\n");
        func_00121B60();
    }
    if (n) {
        VRElem20** pdata = &v->data;
        *pdata = (VRElem20*)TStr_Alloc(n * sizeof(VRElem20), D_004A3F20, 0x5C);
        v->cap = n;
        VRElem20* p = v->data;
        for (; first != last; first++, p++) {
            void* o = func_00139BC0(sizeof(VRElem20), p);
            if (o) func_0020C020(o, first);
            v->count++;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B6F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B6F80 */

/* merge_units: begin func_003B7100 */
#pragma push /* merge_units */
#pragma cplusplus off
typedef struct { union { struct { unsigned int word; unsigned int length; char* data; } l; struct { unsigned char isLong : 1; unsigned char len : 7; char buf[11]; } s; } u; } ShortStr;

/* Forward the character range of src (short or long form) to func_003B9410. */
ShortStr* func_003B9410(ShortStr* self, const char* data, int arg, unsigned int len);

ShortStr* func_003B7100(ShortStr* self, const ShortStr* src, int arg)
{
    const char* data;
    unsigned int len;
    if (!(src->u.l.word & 1)) {
        data = src->u.s.buf;
        len = (unsigned char)src->u.s.len;
    } else {
        data = src->u.l.data;
        len = src->u.l.length;
    }
    return func_003B9410(self, data, arg, len);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B7100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B7100 */
