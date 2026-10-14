/*
 * main/envSettings: range (4 files, 001780A0-00178140)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001780A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cEnvSettings_v0E(void) {
}

void cEnvSettings_v0F(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001780A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001780A0 */

/* merge_units: begin func_001780C0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct Sky {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void SetOn(int on); /* +0x5C */
};

typedef struct cEnvSettings { char pad[0xA4]; Sky* sky; /* +0xA4 */ } cEnvSettings;

/* Script native: turns the sky object of the env settings on. */
extern "C" int Script_cEnvSettings_SkyOn(ScriptArg* args)
{
    cEnvSettings* env = (cEnvSettings*)args[0].p;
    Sky* sky = env->sky;
    if (sky)
    sky->SetOn(1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001780C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001780C0 */

/* merge_units: begin func_00178100 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_00178100 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_00178100;

/* Virtual-call view of Sky: only the slots used here are named (vtable offset in comments). */
struct Sky_00178100 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Show(int hide); /* +0x60 */
};

typedef struct cEnvSettings_00178100 { char pad[0xA4]; Sky_00178100* sky; /* +0xA4 */ } cEnvSettings_00178100;

/* Script native: hides the environment's sky object (virtual +0x60 with 1), if any. Returns 0. */
extern "C" int Script_cEnvSettings_SkyOff(ScriptArg_00178100* args)
{
    Sky_00178100* sky = ((cEnvSettings_00178100*)args[0].p)->sky;
    if (sky)
        sky->Show(1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178100 */

/* merge_units: begin func_00178140 */
#pragma push /* merge_units */
extern int D_004EE860;      /* cEnvSettings script type key */
extern int D_004EE868;      /* cEnvSettings script type id */
extern char D_00555070[];   /* global script filter */
extern int ScriptFilter_Dispatch(void* filter, int a1, int a2);
extern int* cGOBJ_GetScriptTypeKeyPtr(void);
extern void ScriptType_SetParent(int type, int parentType);

/* cEnvSettings derives from cGObj. */
void ScriptType_cEnvSettings_Init(void) {
    ScriptType_SetParent(D_004EE868, *cGOBJ_GetScriptTypeKeyPtr());
}

int cEnvSettings_v0B(void) {
    return D_004EE860;
}

int cEnvSettings_v0C(int a0, int a1) {
    return ScriptFilter_Dispatch(D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00178140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00178140 */
