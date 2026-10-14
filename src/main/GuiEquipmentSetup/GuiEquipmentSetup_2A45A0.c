/*
 * main/GuiEquipmentSetup: range (2 files, 002A45A0-002A4780)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_002A45A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V002A45A0 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); char pad4[0x2420 - 4]; short h2420; char pad2422[0x2C74 - 0x2422]; int x2C74; };
struct O002A45A0 { void* vt; char pad[0x44]; V002A45A0* items[4]; V002A45A0* p58; };
extern "C" {

extern char D_0055DDA0[];
extern char D_004DD7C0[];
extern char D_004E1220[];
extern int D_00506500;
void func_00403310(void* p);
void func_0040F540(void);
void func_002BDC10(void* p);
void func_0041F370(void* p, int f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}
static inline void Del002A45A0(V002A45A0* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, "GuiEquipmentSetup.cc", line);
}
extern "C" O002A45A0* func_002A45A0(O002A45A0* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DD7C0;
        Del002A45A0(self->p58, 0x108);
        for (i = 0; i < 4; i++) {
            self->items[i]->h2420 = 0;
            self->items[i]->x2C74 = 0;
            self->items[i]->v22(1);
            Del002A45A0(self->items[i], 0x10E);
        }
        D_00506500 = 0;
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A45A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A45A0 */

/* merge_units: begin func_002A4780 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_002A4780, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002A4780 */
