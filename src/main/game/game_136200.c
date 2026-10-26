/*
 * main/game: range (3 files, 00136200-00136350)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

/* merge_units: begin func_00136200 */
#pragma push /* merge_units */
typedef struct F1Los136 { void* vt; char pad4[0x1C]; int x20; char pad24[0xC]; Vec4 v30; char st40[0x20]; int x60; char pad64[0xC]; } F1Los136;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern F1Los136* D_004EA0B8;
extern char D_004DA2F0[];
extern void Alloc_Lock(int);
extern void Alloc_Unlock(int);
extern void* Mem_Alloc(int, int, char*, int);
extern void cCollisionModelList_ctor(F1Los136* p, int* a, int* b);
extern Vec4* Vec4_GetZero(void);
extern void Vec4_Assign(Vec4* d, Vec4* s);
extern void cActivationTracker_ctor(void* p);
static inline void* f1_Alloc136(int size, char* file, int line)
{
    void* p;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    p = Mem_Alloc(0, size, file, line);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
    g_ProfileLockDepth--;
    return p;
}
void LosProvider_Create(int arg)
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
            Vec4_Assign(&p->v30, Vec4_GetZero());
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
#pragma pop /* merge_units */
/* merge_units: end func_00136300 */

/* merge_units: begin func_00136350 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_00136350 { void* vt; char m[4]; };
extern "C" {
extern char D_004D9140[];
void std_vector_cGOBJPtr_dtor(void* m, short f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

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
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136350 */
