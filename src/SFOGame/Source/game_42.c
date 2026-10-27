/*
 * SFOGame/Source/game: 4 files, 001361C0-00136200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001361C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_imp_cCollisionFace_reserve(int, int);

int std_vector_cCollisionFace_reserve(int a0, int a1) {
    return std_vector_imp_cCollisionFace_reserve(a0, a1);
}

int cArrayCapacity_Int(char* self) {
    return *(int*)(self + 0);
}

Rel* std_vector_cCollisionFace_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_001361C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001361C0 */

/* merge_units: begin func_00136200 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

typedef struct F1Los136 { void* vt; char pad4[0x1C]; int x20; char pad24[0xC]; Vec4 v30; char st40[0x20]; int x60; char pad64[0xC]; } F1Los136;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern F1Los136* D_004EA0B8;
extern char D_004DA2F0[];
extern void Alloc_Lock(int);
extern void EnableIntc(int);
extern void* cMemMan_Allocate(int, int, char*, int);
extern void cCollisionModelList_ctor(F1Los136* p, int* a, int* b);
extern Vec4* cVector_GetZero(void);
extern void cVector_ctor_cVectorR(Vec4* d, Vec4* s);
extern void cActivationTracker_ctor(void* p);
static inline void* f1_Alloc136(int size, char* file, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = cMemMan_Allocate(0, size, file, line);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    return p;
}
void cLosRequest_cCollisionModelList_Game_InitStatics(int arg)
{
    if (D_004EA0B8 == 0) {
        F1Los136* p = f1_Alloc136(0x70, "los.hh", 0xAE);
        if (p) {
            int b[1];
            int a[1];
            b[0] = 2;
            a[0] = arg;
            cCollisionModelList_ctor(p, a, b);
            p->vt = D_004DA2F0;
            p->x20 = 0;
            cVector_ctor_cVectorR(&p->v30, cVector_GetZero());
            cActivationTracker_ctor(p->st40);
            p->x60 = 0;
        }
        D_004EA0B8 = p;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136200 */

/* merge_units: begin func_00136300 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cActivationTracker_dtor)
static inline void merge_flush_func_00136300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00136300 */

/* merge_units: begin func_00136350 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_00136350 { void* vt; char m[4]; };
extern "C" {
extern char D_004D9140[];
void std_vector_cGOBJPtr_dtor(void* m, short f);
void operator_delete(void* p);

}
extern "C" O_00136350* cCollisionModelList_dtor(O_00136350* self, short del)
{
    if (self) {
        self->vt = D_004D9140;
        if (self->m) std_vector_cGOBJPtr_dtor(self->m, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136350 */
