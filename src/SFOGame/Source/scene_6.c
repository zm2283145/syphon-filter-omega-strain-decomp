/*
 * SFOGame/Source/scene: 6 files, 0013DF80-0013E1A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013DF80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_cGOBJPtr_end(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Iter* cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(Iter* d, Iter* s) {
    d->p = s->p;
    return d;
}

void std_vector_cGOBJPtr_begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cTerrain_GetBBox(char* self) {
    return self + 560;
}
static inline void merge_flush_func_0013DF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013DF80 */

/* merge_units: begin func_0013DFD0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cPlane_dtor)
static inline void merge_flush_func_0013DFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013DFD0 */

/* merge_units: begin func_0013E020 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P_0013E020 { char pad[0xE8]; unsigned char bE8; };
struct A_0013E020 { char pad[0x3310]; P_0013E020* p; };
extern "C" void* cHuman_GetFloorPoly(A_0013E020* a)
{
    bool ok = false;
    P_0013E020* p = a->p;
    if (p && p->bE8) ok = true;
    return ok ? (char*)p + 0x100 : 0;
}
static inline void merge_flush_func_0013E020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013E020 */

/* merge_units: begin func_0013E060 */
#pragma push /* merge_units */
int cGOBJ_GetFloorPlane(void) {
    return 0;
}
static inline void merge_flush_func_0013E060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013E060 */

/* merge_units: begin func_0013E070 */
#pragma push /* merge_units */
#pragma cplusplus on
struct A_E070 { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; };
struct It_E070 { A_E070** p; };
struct Vec_E070;
extern "C" {
void* nGobjManager_GetGOBJList(void);
Vec_E070* cObjList_cGOBJPtr_GetList(void* arr);
void cArray_cGOBJPtr_Begin(It_E070* out, Vec_E070* v);
void cArray_cGOBJPtr_End(It_E070* out, Vec_E070* v);
void cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(It_E070* out, It_E070* in);
void* GetGOBJActivationMan(void);
void cGOBJActivationMan_Deactivate(void* mgr, A_E070* a, int f);
}
static inline int Ne_E070(It_E070* a, It_E070* b) { return (a->p == b->p) ^ 1; }
extern "C" void cScene_DeactivateAll(void)
{
    It_E070 it;
    It_E070 end;
    It_E070 tb;
    It_E070 te;
    void* arr = nGobjManager_GetGOBJList();
    cArray_cGOBJPtr_Begin(&tb, cObjList_cGOBJPtr_GetList(arr));
    cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&it, &tb);
    for (cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(arr)), cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te); Ne_E070(&it, &end); cArray_cGOBJPtr_End(&te, cObjList_cGOBJPtr_GetList(arr)), cArray_cGOBJPtr_ConstIterator_ctor_IteratorR(&end, &te)) {
        A_E070* a = *it.p;
        if (a) {
            unsigned char ok = a->b2D != 0 && a->b2C != 0 && !(a->b2E != 0);
            if (ok)
                cGOBJActivationMan_Deactivate(GetGOBJActivationMan(), a, 1);
        }
        it.p++;
    }
}
static inline void merge_flush_func_0013E070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013E070 */

/* merge_units: begin func_0013E1A0 */
#pragma push /* merge_units */
#include "loose00_types.h"

extern int nActivation_FindBestSectorInActivation(void* position, int cachedRegion);

/* Find the region containing position, starting from the cached region (+0x08). */
int cScene_FindBestSectorInActivation(RegionCache* self, void* position) {
    int cached;

    cached = self->region;
    return nActivation_FindBestSectorInActivation(position, cached);
}
static inline void merge_flush_func_0013E1A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013E1A0 */
