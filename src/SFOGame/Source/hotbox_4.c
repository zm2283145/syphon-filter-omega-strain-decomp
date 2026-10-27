/*
 * SFOGame/Source/hotbox: 2 files, 0016FC70-0016FCD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016FC70 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cDisableMsg_dtor, D_004E0860, cMessage_dtor)
static inline void merge_flush_func_0016FC70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016FC70 */

/* merge_units: begin func_0016FCD0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cHotbox: only the slots used here are named (vtable offset in comments). */
struct cHotbox {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cHotbox::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cHotbox_Enable(ScriptArg* args)
{
    cHotbox* obj = (cHotbox*)args[0].p;
    obj->Enable(-1);
    return 0;
}
static inline void merge_flush_func_0016FCD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016FCD0 */
