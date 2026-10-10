#include "types.h"

extern char D_0049AB30[];
extern char D_0049AB48[];
extern char D_0049AB50[];
extern char D_0049AB10[];
extern char D_0048B2F8[];
extern char D_004FFC90[];
extern char D_00555070[]; /* script interpreter */
extern int sprintf(char* buf, const char* fmt, ...);
extern void* Archive_Open(void* self, char* path, int a, int b);
extern void func_003E2140(void* interp, void* script);
extern void ScriptMgr_LoadScript(void* interp, const char* name, int a);
extern int cScriptInterpreter_CheckAllReferences(void* interp);
extern void cScriptInterpreter_ExecuteInitCode(void* interp);
extern void ScriptMgr_CallFunction(void* interp, const char* name, int a);

/* Loads and starts the arcade script, then loads the second resource. */
void IArcade_Init(void* self)
{
    char path[0x80];
    sprintf(path, D_0049AB30, D_0048B2F8);
    func_003E2140(D_00555070, Archive_Open(self, path, 0, 0));
    ScriptMgr_LoadScript(D_00555070, D_0049AB48, 0);
    cScriptInterpreter_CheckAllReferences(D_00555070);
    cScriptInterpreter_ExecuteInitCode(D_00555070);
    ScriptMgr_CallFunction(D_00555070, D_0049AB50, 0);
    sprintf(path, D_0049AB10, D_0048B2F8, D_004FFC90);
    Archive_Open(self, path, 0, 1);
}
