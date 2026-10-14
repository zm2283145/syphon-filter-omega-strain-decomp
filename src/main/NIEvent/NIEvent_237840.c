/*
 * main/NIEvent: range (8 files, 00237840-00237990)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "NIEvent_types.h"

/* merge_units: begin func_00237840 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void func_0023E3D0(void* obj, float speed);

/* SetSpeed(object, speed): float argument is passed through a stack slot. */
int Script_cNIEventOBJ_SetSpeed(NIEventScriptArg* args) {
    NIEventScriptArg speed[1];

    speed[0].i = args[1].i;
    func_0023E3D0(args[0].p, speed[0].f);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237840 */

/* merge_units: begin func_00237870 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cNIEventOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void SetEndState(); /* +0x128 */
};

/* Script native: cNIEventOBJ::SetEndState() on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_SetEndState(ScriptArg* args)
{
    cNIEventOBJ* obj = (cNIEventOBJ*)args[0].p;
    obj->SetEndState();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237870 */

/* merge_units: begin func_002378A0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_002378A0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_002378A0;

/* Virtual-call view of cNIEventOBJ: only the slots used here are named (vtable offset in comments). */
struct cNIEventOBJ_002378A0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int who); /* +0x68 */
};

/* Script native: cNIEventOBJ::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Disable(ScriptArg_002378A0* args)
{
    cNIEventOBJ_002378A0* obj = (cNIEventOBJ_002378A0*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002378A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002378A0 */

/* merge_units: begin func_002378D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNIEventOBJ_002378D0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int value); /* +0x64 */
};

/* Script native: cNIEventOBJ::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Enable(ScriptArg* args)
{
    cNIEventOBJ_002378D0* obj = (cNIEventOBJ_002378D0*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002378D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002378D0 */

/* merge_units: begin func_00237900 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00237900 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00237900;

/* Virtual-call view of cNIEventOBJ: only the slots used here are named (vtable offset in comments). */
struct cNIEventOBJ_00237900 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44();
    virtual void Reset(); /* +0x11C */
};

/* Script native: cNIEventOBJ::Reset() on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Reset(ScriptArg_00237900* args)
{
    cNIEventOBJ_00237900* obj = (cNIEventOBJ_00237900*)args[0].p;
    obj->Reset();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237900 */

/* merge_units: begin func_00237930 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cNIEventOBJ_00237930 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43();
    virtual void Stop(int value); /* +0x118 */
};

/* Script native: cNIEventOBJ::Stop(1) on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Stop(ScriptArg* args)
{
    cNIEventOBJ_00237930* obj = (cNIEventOBJ_00237930*)args[0].p;
    obj->Stop(1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237930(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237930 */

/* merge_units: begin func_00237960 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00237960 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00237960;

/* Virtual-call view of cNIEventOBJ: only the slots used here are named (vtable offset in comments). */
struct cNIEventOBJ_00237960 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42();
    virtual void Play(); /* +0x114 */
};

/* Script native: cNIEventOBJ::Play() on args[0]; returns 0. */
extern "C" int Script_cNIEventOBJ_Play(ScriptArg_00237960* args)
{
    cNIEventOBJ_00237960* obj = (cNIEventOBJ_00237960*)args[0].p;
    obj->Play();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237960 */

/* merge_units: begin func_00237990 */
#pragma push /* merge_units */
extern int D_004F7CA0; /* cNIEventOBJ script type key */
extern int D_004F7CA8; /* cNIEventOBJ script type id */
extern int D_004F7D20; /* cNINotice script type key */
extern char D_00555070[]; /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void); /* address of the cGObj type key */
extern int ScriptType_AddAccepted(int type, int acceptedType);
extern void ScriptType_SetParent(int type, int parentType);

/* cNIEventOBJ derives from cGObj and accepts cNINotice messages. */
int ScriptType_cNIEventOBJ_Init(void) {
    int* parent = cGOBJ_GetScriptTypeKeyPtr();
    ScriptType_SetParent(D_004F7CA8, *parent);
    return ScriptType_AddAccepted(D_004F7CA8, D_004F7D20);
}

void* func_002379D0(void* self) {
    return self;
}

int* func_002379E0(void) {
    return &D_004F7CA0;
}

int cNIEventOBJ_v0B(void) {
    return D_004F7CA0;
}

int cNIEventOBJ_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237990 */
