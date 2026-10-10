#include "types.h"
extern void* func_003E1520(int handle);
extern int ScriptMgr_ReloadScript(void* mgr, int name);
/* Script: cScriptInterpreter.ReloadScript(name). */
int Script_cScriptInterpreter_ReloadScript(int* args)
{
    volatile int result; /* both staged through the stack */
    volatile int name = args[1];
    result = ScriptMgr_ReloadScript(func_003E1520(args[0]), name);
    return result;
}
