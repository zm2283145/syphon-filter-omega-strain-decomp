/*
 * main/scriptManager: range (2 files, 003E20A0-003E2140)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptManager_types.h"

/* merge_units: begin func_003E20A0 */
#pragma push /* merge_units */
extern unsigned char D_004938D0;
extern int ScriptMgr_LoadScript(void* self, const char* name, int a2);
extern void cScriptInterpreter_ExecuteInitCode(void* self);
extern int ScriptMgr_CallFunction(void* self, const char* name, int a2);
extern unsigned char cScriptInterpreter_CheckAllReferences(void* self);

/* Runs the load steps in order; returns 1 only if every step succeeds. */
unsigned char Script_StartLevel(void* self)
{
    unsigned char ok = 0;
    if (D_004938D0 && ScriptMgr_LoadScript(self, "init", 0) && ScriptMgr_LoadScript(self, "utils", 0)) {
        cScriptInterpreter_ExecuteInitCode(self);
        ok = ScriptMgr_CallFunction(self, "init::Init", 0) != 0;
        if (ok)
            ok = cScriptInterpreter_CheckAllReferences(self);
    }
    return ok;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E20A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E20A0 */

/* merge_units: begin func_003E2140 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003E2140(ScriptManager* self, int value) {
    self->unk4E90 = value;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E2140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E2140 */
