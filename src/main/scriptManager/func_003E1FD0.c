#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int ScriptMgr_CallFunction();         
int ScriptMgr_LoadScript();                   
int cScriptInterpreter_CheckAllReferences(int );  
int cScriptInterpreter_ExecuteInitCode(int );       
int func_003D7930();                               
int func_003D7E30();                                  
extern unsigned char D_004938D0;
extern int D_004BD988;
extern int D_004BD990;
extern int D_004BD9A0;
extern int D_004BD9C0;

int ScriptMgr_InitClient(int arg0) {
    int var_s0;

    var_s0 = 0;
    if ((D_004938D0 != 0) && (ScriptMgr_LoadScript(arg0, &D_004BD988, 1) != 0)) {
        cScriptInterpreter_ExecuteInitCode(arg0);
        var_s0 = ScriptMgr_CallFunction(arg0, &D_004BD990, 0) != 0;
        if (var_s0 == 0) {
            func_003D7930(&D_004BD9A0);
        } else {
            var_s0 = cScriptInterpreter_CheckAllReferences(arg0) & 0xFF;
            if (var_s0 == 0) {
                func_003D7930(&D_004BD9C0);
            }
        }
        func_003D7E30();
        F_(arg0, 0x4E60, int) = F_(arg0, 0xC, int);
        F_(arg0, 0x4E64, int) = F_(arg0, 0x28, int);
    }
    return var_s0;
}
