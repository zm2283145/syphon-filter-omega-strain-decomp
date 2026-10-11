#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int ScriptMgr_LoadScript(int, int, int);                
char * func_003E0BE0();                        
extern unsigned char D_004938D0;

int func_003E15B0(int arg0, int arg1, int *arg2, int *arg3) {
    char * var_s0;

    if (D_004938D0 != 0) {
        var_s0 = func_003E0BE0();
        if (var_s0 != NULL) {
            *arg2 = F_(var_s0, 0x38, int);
            *arg3 = F_(var_s0, 0x48, int);
        } else if (ScriptMgr_LoadScript(arg0, arg1, 0) != 0) {
            var_s0 = func_003E0BE0(arg0, arg1);
            if (var_s0 != NULL) {
                *arg2 = F_(var_s0, 0x38, int);
                *arg3 = F_(var_s0, 0x48, int);
            }
        }
        return var_s0 != NULL;
    }
    return 1;
}
