/*
 * main/game: 2 files, 00139BA0-00139BD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00139BA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Vec4* func_00139BA0(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

Vec4* func_00139BB0(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

int func_00139BC0(int a0, int a1) {
    return a1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00139BA0 */

/* merge_units: begin func_00139BD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tstr_types.h"

struct E139BD0 { int w[56]; };
struct V139BD0 { unsigned int cap; unsigned int count; E139BD0* data; };
extern "C" {
extern char D_0049ABB0[];
#if 0 /* merge_units */
void* func_00139BC0(unsigned int size, void* p);
#endif /* merge_units */
#define func_00139BC0(a0, a1) ((void *)func_00139BC0((int)(a0), (int)(a1))) /* merge_units */

void func_00139D30(void* dst, const E139BD0* src);
}
extern "C" void func_00139BD0(V139BD0* v, unsigned int n, const E139BD0* val)
{
    if (n) {
        if (n > 0x6DB6D) {
            func_00123BE8(D_00489738->stream, D_0049ABB0);
            func_00121B60();
        }
        E139BD0** pdata = &v->data;
        *pdata = (E139BD0*)TStr_Alloc(n * sizeof(E139BD0), "allocator.hh", 0x5C);
        v->cap = n;
        E139BD0* p = v->data;
        E139BD0* end = p + n;
        for (; p < end; p++) {
            void* o = func_00139BC0(sizeof(E139BD0), p);
            if (o) func_00139D30(o, val);
            v->count++;
        }
    }
}
#undef func_00139BC0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00139BD0 */
