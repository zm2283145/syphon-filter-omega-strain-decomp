/*
 * main/skybox: range (3 files, 003BBD00-003BBD60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003BBD00 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cSKYBOX_GOBJ: only the slots used here are named (vtable offset in comments). */
struct cSKYBOX_GOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int who); /* +0x68 */
};

/* Script native: cSKYBOX_GOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cSKYBOX_GOBJ_Disable(ScriptArg* args)
{
    cSKYBOX_GOBJ* obj = (cSKYBOX_GOBJ*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BBD00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BBD00 */

/* merge_units: begin func_003BBD30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_003BBD30 { int i; float f; void* p; unsigned char b; } ScriptArg_003BBD30;

struct cSKYBOX_GOBJ_003BBD30 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int value); /* +0x64 */
};

/* Script native: cSKYBOX_GOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cSKYBOX_GOBJ_Enable(ScriptArg_003BBD30* args)
{
    cSKYBOX_GOBJ_003BBD30* obj = (cSKYBOX_GOBJ_003BBD30*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BBD30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BBD30 */

/* merge_units: begin func_003BBD60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cSKYBOX_GOBJ script type registration and class helpers.
 */


extern int D_00542C98;   /* cSKYBOX_GOBJ class type id */
extern int D_00542CA0;   /* cSKYBOX_GOBJ script type */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* Registers the cSKYBOX_GOBJ script type under its parent type. */
void ScriptType_cSKYBOX_GOBJ_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();

    ScriptType_SetParent(D_00542CA0, *parent);
}

int cSKYBOX_GOBJ_v0B(void) {
    return D_00542C98;
}

int cSKYBOX_GOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BBD60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BBD60 */
