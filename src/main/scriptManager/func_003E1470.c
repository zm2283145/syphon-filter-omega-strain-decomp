#include "types.h"
extern void* func_003E1520(int handle);
extern int ScriptMgr_LoadScript(void* mgr, int name, int flags);
/* Script: cScriptInterpreter.LoadScript(name). */
int Script_cScriptInterpreter_LoadScript(int* args)
{
    volatile int result; /* both staged through the stack */
    volatile int name = args[1];
    result = ScriptMgr_LoadScript(func_003E1520(args[0]), name, 0);
    return result;
}
