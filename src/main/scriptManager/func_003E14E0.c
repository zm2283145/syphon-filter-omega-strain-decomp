/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern void cScriptInterpreter_ExecuteInitCode(void* interp);
extern void* func_003E1520(void* self);

/* Script native: runs the init code of interpreter args[0]. */
int Script_cScriptInterp_ExecuteInitCode(ScriptArg* args) {
    cScriptInterpreter_ExecuteInitCode(func_003E1520(args[0].p));
    return 0;
}

void func_003E1510(void) {
}
