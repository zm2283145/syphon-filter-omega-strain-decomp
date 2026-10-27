/*
 * main/gameLight: range (9 files, 00178FA0-00179160)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00178FA0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cGameDirectionalLight {
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
    virtual void TurnOff(); /* +0x114 */
};

/* Script native: cGameDirectionalLight::TurnOff() on args[0]; returns 0. */
extern "C" int Script_cGameDirectionalLight_TurnOff(ScriptArg* args)
{
    cGameDirectionalLight* obj = (cGameDirectionalLight*)args[0].p;
    obj->TurnOff();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178FA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178FA0 */

/* merge_units: begin func_00178FD0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00178FD0 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00178FD0;

/* Virtual-call view of cGameDirectionalLight: only the slots used here are named (vtable offset in comments). */
struct cGameDirectionalLight_00178FD0 {
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
    virtual void TurnOn(); /* +0x110 */
};

/* Script native: cGameDirectionalLight::TurnOn() on args[0]; returns 0. */
extern "C" int Script_cGameDirectionalLight_TurnOn(ScriptArg_00178FD0* args)
{
    cGameDirectionalLight_00178FD0* obj = (cGameDirectionalLight_00178FD0*)args[0].p;
    obj->TurnOn();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178FD0 */

/* merge_units: begin func_00179000 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGameDirectionalLight script type registration and class helpers.
 */


extern int D_004EE8D8;   /* cGameDirectionalLight class type id */
extern int D_004EE8E0;   /* cGameDirectionalLight script type */
extern int D_004EE898;   /* cGameLight class type id (parent) */
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(void* filter, int a0, int a1);
extern void cScriptBase_declareParent(int type, int parentType);

/* Registers the cGameDirectionalLight script type under its parent type. */
void cGameDirectionalLight_SOBJ_init(void) {
    cScriptBase_declareParent(D_004EE8E0, D_004EE898);
}

int cGameDirectionalLight_getSOBJClassId(void) {
    return D_004EE8D8;
}

int cGameDirectionalLight_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179000 */

/* merge_units: begin func_00179050 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cGameSceneLight {
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
    virtual void TurnOff(); /* +0x114 */
};

/* Script native: cGameSceneLight::TurnOff() on args[0]; returns 0. */
extern "C" int Script_cGameSceneLight_TurnOff(ScriptArg* args)
{
    cGameSceneLight* obj = (cGameSceneLight*)args[0].p;
    obj->TurnOff();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179050 */

/* merge_units: begin func_00179080 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00179080 { int i; float f; void* p; } ScriptArg_00179080;

/* Virtual-call view of cGameSceneLight: only the slots used here are named (vtable offset in comments). */
struct cGameSceneLight_00179080 {
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
    virtual void TurnOn(); /* +0x110 */
};

/* Script native: cGameSceneLight::TurnOn() on args[0]; returns 0. */
extern "C" int Script_cGameSceneLight_TurnOn(ScriptArg_00179080* args)
{
    cGameSceneLight_00179080* obj = (cGameSceneLight_00179080*)args[0].p;
    obj->TurnOn();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179080 */

/* merge_units: begin func_001790B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGameSceneLight script type registration and class helpers.
 */


extern int D_004EE8B8;   /* cGameSceneLight class type id */
extern int D_004EE8C0;   /* cGameSceneLight script type */

/* Registers the cGameSceneLight script type under its parent type. */
void cGameSceneLight_SOBJ_init(void) {
    cScriptBase_declareParent(D_004EE8C0, D_004EE898);
}

int cGameSceneLight_getSOBJClassId(void) {
    return D_004EE8B8;
}

int cGameSceneLight_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001790B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001790B0 */

/* merge_units: begin func_00179100 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00179100 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00179100;

/* Virtual-call view of cGameLight: only the slots used here are named (vtable offset in comments). */
struct cGameLight {
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
    virtual void TurnOff(); /* +0x114 */
};

/* Script native: cGameLight::TurnOff() on args[0]; returns 0. */
extern "C" int Script_cGameLight_TurnOff(ScriptArg_00179100* args)
{
    cGameLight* obj = (cGameLight*)args[0].p;
    obj->TurnOff();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179100 */

/* merge_units: begin func_00179130 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cGameLight_00179130 {
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
    virtual void TurnOn(); /* +0x110 */
};

/* Script native: cGameLight::TurnOn() on args[0]; returns 0. */
extern "C" int Script_cGameLight_TurnOn(ScriptArg* args)
{
    cGameLight_00179130* obj = (cGameLight_00179130*)args[0].p;
    obj->TurnOn();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179130 */

/* merge_units: begin func_00179160 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cGameLight script type registration and class helpers.
 */


extern int D_004EE8A0;   /* cGameLight script type */
extern int* cGOBJ_SOBJ_getClassId(void);

/* Registers the cGameLight script type under its parent type. */
void cGameLight_SOBJ_init(void) {
    int* parent = cGOBJ_SOBJ_getClassId();

    cScriptBase_declareParent(D_004EE8A0, *parent);
}

int cGameLight_getSOBJClassId(void) {
    return D_004EE898;
}

int cGameLight_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00179160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00179160 */
