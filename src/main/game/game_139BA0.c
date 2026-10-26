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

Vec4* cCollisionModel_FaceLocator_opAssign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

Vec4* cCollisionModel_FaceProperties_opAssign(Vec4* d, Vec4* s) {
    *d = *s;
    return d;
}

int Mem_PlacementNew(int a0, int a1) {
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
void* Mem_PlacementNew(unsigned int size, void* p);
#endif /* merge_units */
#define Mem_PlacementNew(a0, a1) ((void *)Mem_PlacementNew((int)(a0), (int)(a1))) /* merge_units */

void cLosRequest_cCollisionModelList_Game_ctor(void* dst, const E139BD0* src);
}
extern "C" void std_vector_imp_cLosRequest_cCollisionModelList_Game_init(V139BD0* v, unsigned int n, const E139BD0* val)
{
    if (n) {
        if (n > 0x6DB6D) {
            Libc_Fprintf(D_00489738->stream, D_0049ABB0);
            Libc_Abort();
        }
        E139BD0** pdata = &v->data;
        *pdata = (E139BD0*)TStr_Alloc(n * sizeof(E139BD0), "allocator.hh", 0x5C);
        v->cap = n;
        E139BD0* p = v->data;
        E139BD0* end = p + n;
        for (; p < end; p++) {
            void* o = Mem_PlacementNew(sizeof(E139BD0), p);
            if (o) cLosRequest_cCollisionModelList_Game_ctor(o, val);
            v->count++;
        }
    }
}
#undef Mem_PlacementNew /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00139BD0 */
