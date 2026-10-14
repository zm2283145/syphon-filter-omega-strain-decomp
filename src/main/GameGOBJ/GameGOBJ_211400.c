/*
 * main/GameGOBJ: range (4 files, 00211400-002114D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"
#include "types.h"

/* merge_units: begin func_00211400 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cPathedGOBJ script type registration and accessors.
 */


extern int D_004F54D0;   /* cGameGOBJ script-type value */
extern int D_004F54F0;   /* cPathedGOBJ script-type value */
extern int D_004F54F8;   /* cPathedGOBJ script-type key */
extern int D_004F5638;   /* cPathedNotice script-type value */
extern char D_00555070[];
extern int ScriptFilter_Dispatch(void* filter, int a0, int a1);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int base);

/* Registers the cPathedGOBJ script type under cGameGOBJ; accepts cPathedNotice. */
int ScriptType_cPathedGOBJ_Init(void) {
    ScriptType_SetParent(D_004F54F8, D_004F54D0);
    return ScriptType_AddAccepted(D_004F54F8, D_004F5638);
}

int cPathedGOBJ_v0B(void) {
    return D_004F54F0;
}

int PathObj_ScriptFilter(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00211400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00211400 */

/* merge_units: begin func_00211470 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Virtual-call view of cGameGOBJ: only the slots used here are named (vtable offset in comments). */
struct cGameGOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int mode); /* +0x68 */
};

/* Script native: cGameGOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cGameGOBJ_Disable(ScriptArg* args)
{
    cGameGOBJ* obj = (cGameGOBJ*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00211470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00211470 */

/* merge_units: begin func_002114A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_002114A0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_002114A0;

/* Virtual-call view of cGameGOBJ: only the slots used here are named (vtable offset in comments). */
struct cGameGOBJ_002114A0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cGameGOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cGameGOBJ_Enable(ScriptArg_002114A0* args)
{
    cGameGOBJ_002114A0* obj = (cGameGOBJ_002114A0*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002114A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002114A0 */

/* merge_units: begin func_002114D0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 * cGameGOBJ script type registration and accessors.
 */


extern int D_004F54D8;   /* cGameGOBJ script-type key */
extern int D_004F55D8;   /* cGOBJTriggerEventMsg script-type value */
extern int* cGOBJ_GetScriptTypeKeyPtr(void);

/* Registers the cGameGOBJ script type under cGOBJ; accepts cGOBJTriggerEventMsg. */
int ScriptType_cGameGOBJ_Init(void) {
    int* base;

    base = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F54D8, *base);
    return ScriptType_AddAccepted(D_004F54D8, D_004F55D8);
}

int cGameGOBJ_v0B(void) {
    return D_004F54D0;
}

int cGameGOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002114D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002114D0 */
