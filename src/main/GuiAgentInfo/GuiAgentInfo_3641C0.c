/*
 * main/GuiAgentInfo: range (2 files, 003641C0-00364340)
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
int cMemMan_Deallocate();

/* merge_units: begin func_003641C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V3641C0 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); };
struct O3641C0 { char pad[0x48]; V3641C0* p48; char pad4C[0x44]; V3641C0* p90; };
extern "C" {
extern void* D_004FFC04;
void GuiWidget_onRemove(void* p);
void cGameFrontEnd_CloseCharacter(void* p, int f);
}
static inline void Del3641C0(V3641C0* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    cMemMan_Deallocate(0, o, "GuiAgentInfo.cc", line);
}
extern "C" void GuiAgentDisplay_onRemove(O3641C0* s)
{
    GuiWidget_onRemove(s);
    cGameFrontEnd_CloseCharacter(D_004FFC04, 0);
    if (s->p48) {
        s->p48->v22(1);
        Del3641C0(s->p48, 0x5B);
        s->p48 = 0;
    }
    {
        V3641C0* p = s->p90;
        if (p) {
            Del3641C0(p, 0x61);
            s->p90 = 0;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003641C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003641C0 */

/* merge_units: begin func_00364340 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_00364340, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00364340 */
