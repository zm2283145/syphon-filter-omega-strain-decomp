/*
 * main/decals: decals.cc (2 files, 00279D80-0027A020)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00279D80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int heap, void* p, char* file, int line);
void operator_delete(void* p);
}
struct S_00279D80 { void** a; void** b; int na; int nb; };
static inline void Free_00279D80(void* p, int line) { AllocGuard g; Mem_Free(0, p, "decals.cc", line); }
extern "C" S_00279D80* DecalMgr_dtor(S_00279D80* self, short flag)
{
    if (self) {
        int i;
        for (i = 0; i < self->na; i++) Free_00279D80(self->a[i], 0x87);
        { int j; for (j = 0; j < self->nb; j++) Free_00279D80(self->b[j], 0x89); }
        Free_00279D80(self->a, 0x8B);
        Free_00279D80(self->b, 0x8C);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00279D80 */

/* merge_units: begin func_0027A020 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Item_27A020 { int f0; char pad4[0x4C]; int f50; int f54; int f58; float f5C; };
struct Mgr_27A020 {
    Item_27A020** a; Item_27A020** b; int na; int nb; int f10; int f14; int f18; int f1C;
    int f20; int f24; char pad28[8]; char f30[1];
};
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
void BloodDecal_BuildDirections(void* p, int n);
extern char D_004A9238[];
extern int D_00543798;
}
extern "C" Mgr_27A020* DecalMgr_ctor(Mgr_27A020* self, int na, int nb) {
    self->a = 0;
    self->b = 0;
    self->na = na;
    self->nb = nb;
    self->f10 = 0;
    self->f14 = 0;
    self->f18 = 0;
    self->f1C = 0;
    { Item_27A020** t; { int sz = self->na * 4; AllocGuard g; t = (Item_27A020**)Mem_Alloc(0, sz, D_004A9238, 0x74); } self->a = t; }
    { Item_27A020** t; { int sz = self->nb * 4; AllocGuard g; t = (Item_27A020**)Mem_Alloc(0, sz, D_004A9238, 0x75); } self->b = t; }
    {
        int i;
        for (i = 0; i < self->na; i++) {
            Item_27A020* p;
            { AllocGuard g; p = (Item_27A020*)Mem_Alloc(0, 0x60, D_004A9238, 0x78); }
            if (p) { p->f0 = 0; p->f50 = 0; p->f54 = -1; p->f58 = 0; p->f5C = -1.0f; }
            self->a[i] = p;
        }
    }
    {
        int i;
        for (i = 0; i < self->nb; i++) {
            Item_27A020* p;
            { AllocGuard g; p = (Item_27A020*)Mem_Alloc(0, 0x60, D_004A9238, 0x7A); }
            if (p) { p->f0 = 0; p->f50 = 0; p->f54 = -1; p->f58 = 0; p->f5C = -1.0f; }
            self->b[i] = p;
        }
    }
    self->f20 = (int)(0.1f * (float)self->na);
    self->f24 = (int)(0.1f * (float)self->nb);
    BloodDecal_BuildDirections(self->f30, 0x20);
    D_00543798 = self->nb;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0027A020 */
