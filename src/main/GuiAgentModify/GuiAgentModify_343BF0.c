/*
 * main/GuiAgentModify: range (2 files, 00343BF0-00343DB0)
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

/* merge_units: begin func_00343BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V00343BF0 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); char pad4[0x2420 - 4]; short h2420; char pad2422[0x2C74 - 0x2422]; int x2C74; };
struct O00343BF0 { void* vt; char pad[0x88]; V00343BF0* p8C; V00343BF0* p90; };
extern "C" {

extern char g_AgentPartCache[];
extern char D_004DE920[];
extern char D_004E1220[];
extern int D_00506500;
void AgentPartCache_Unlock(void* p);
void World_ClearPendingIfLoaded(void);
void GuiEquipmentModify_RingRelease(void* p);
void GuiWidget_Destroy(void* p, int f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}
static inline void Del00343BF0(V00343BF0* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, "GuiAgentModify.cc", line);
}
extern "C" O00343BF0* func_00343BF0(O00343BF0* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DE920;
        Del00343BF0(self->p90, 0x176);
        self->p8C->v22(1);
        Del00343BF0(self->p8C, 0x178);
        AgentPartCache_Unlock(g_AgentPartCache);
        World_ClearPendingIfLoaded();
        if (self) {
            self->vt = D_004E1220;
            GuiWidget_Destroy(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00343BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00343BF0 */

/* merge_units: begin func_00343DB0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_00343DB0, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00343DB0 */
