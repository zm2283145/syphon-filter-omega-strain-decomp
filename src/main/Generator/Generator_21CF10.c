/*
 * main/Generator: range (3 files, 0021CF10-0021CF70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021CF10 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cGenerator {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int value); /* +0x68 */
};

/* Script native: cGenerator::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_Disable(ScriptArg* args)
{
    cGenerator* obj = (cGenerator*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CF10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CF10 */

/* merge_units: begin func_0021CF40 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0021CF40 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_0021CF40;

/* Virtual-call view of cGenerator: only the slots used here are named (vtable offset in comments). */
struct cGenerator_0021CF40 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cGenerator::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_Enable(ScriptArg_0021CF40* args)
{
    cGenerator_0021CF40* obj = (cGenerator_0021CF40*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CF40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CF40 */

/* merge_units: begin func_0021CF70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F56D8;      /* NPC message base script type key */
extern int D_004F56F0;      /* cSpawnedNPCMsg type key */
extern int D_004F56F8;      /* cSpawnedNPCMsg script type id */
extern int D_004F5700;      /* cDespawnedNPCMsg type key */
extern int D_004F5708;      /* cDespawnedNPCMsg script type id */
extern int D_004F5710;      /* cGenerator script type key */
extern int D_004F5718;      /* cGenerator script type id */
extern char D_00555070[];   /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern int ScriptType_AddAccepted(int type, int iface);
extern void ScriptType_SetParent(int type, int parentType);

/* cGenerator derives from cGObj and accepts the spawned/despawned messages. */
int ScriptType_cGenerator_Init(void) {
    ScriptType_SetParent(D_004F5718, *cGOBJ_GetScriptTypeKeyPtr());
    ScriptType_AddAccepted(D_004F5718, D_004F56F0);
    return ScriptType_AddAccepted(D_004F5718, D_004F5700);
}

int cGenerator_v0B(void) {
    return D_004F5710;
}

int cGenerator_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}

void ScriptType_cDespawnedNPCMsg_Init(void) {
    ScriptType_SetParent(D_004F5708, D_004F56D8);
}

int cDespawnedNPCMsg_v03(void) {
    return D_004F5700;
}

void ScriptType_cSpawnedNPCMsg_Init(void) {
    ScriptType_SetParent(D_004F56F8, D_004F56D8);
}

int cSpawnedNPCMsg_v03(void) {
    return D_004F56F0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CF70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CF70 */
