#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int ScriptMgr_LoadScript(int, int, int);                
char * ScriptMgr_FindResource();                        
unsigned int D_004938D0[2] = { 0x1, 0x0 };

int ScriptMgr_LookupResource(int arg0, int arg1, int *arg2, int *arg3) {
    char * var_s0;

    if ((*(unsigned char*)D_004938D0) != 0) {
        var_s0 = ScriptMgr_FindResource();
        if (var_s0 != NULL) {
            *arg2 = F_(var_s0, 0x38, int);
            *arg3 = F_(var_s0, 0x48, int);
        } else if (ScriptMgr_LoadScript(arg0, arg1, 0) != 0) {
            var_s0 = ScriptMgr_FindResource(arg0, arg1);
            if (var_s0 != NULL) {
                *arg2 = F_(var_s0, 0x38, int);
                *arg3 = F_(var_s0, 0x48, int);
            }
        }
        return var_s0 != NULL;
    }
    return 1;
}
