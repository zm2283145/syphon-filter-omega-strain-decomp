#include "types.h"

extern unsigned char D_004938D0;
extern char D_004BD9E8[];
extern char D_004BD9F0[];
extern char D_004BD9F8[];
extern int ScriptMgr_LoadScript(void* self, const char* name, int a2);
extern void cScriptInterpreter_ExecuteInitCode(void* self);
extern int ScriptMgr_CallFunction(void* self, const char* name, int a2);
extern unsigned char cScriptInterpreter_CheckAllReferences(void* self);

/* Runs the load steps in order; returns 1 only if every step succeeds. */
unsigned char func_003E20A0(void* self)
{
    unsigned char ok = 0;
    if (D_004938D0 && ScriptMgr_LoadScript(self, D_004BD9E8, 0) && ScriptMgr_LoadScript(self, D_004BD9F0, 0)) {
        cScriptInterpreter_ExecuteInitCode(self);
        ok = ScriptMgr_CallFunction(self, D_004BD9F8, 0) != 0;
        if (ok)
            ok = cScriptInterpreter_CheckAllReferences(self);
    }
    return ok;
}
