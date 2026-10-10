#include "types.h"

typedef struct LoadScriptArgs {
    int interp;
    int name;
    int flag;
} LoadScriptArgs;

extern int func_003E1520(int handle);
extern int ScriptMgr_LoadScript(int interp, int name, int flag);

/* Script native: cScriptInterpreter.LoadScript(name, flag). */
int Script_cScriptInterpreter_LoadScript_2(LoadScriptArgs* args) {
    volatile int result;
    volatile int name;
    int flag = args->flag != 0;
    int interp;
    name = args->name;
    interp = func_003E1520(args->interp);
    result = ScriptMgr_LoadScript(interp, name, flag);
    return result;
}
