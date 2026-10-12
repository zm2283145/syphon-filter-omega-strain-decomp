#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int *ScriptEnum_GetById();                          
int *ScriptType_GetRecord(int);                            
extern char D_004BD378[];
extern char D_004BD380[];
extern char D_004BD388[];
extern char D_004BD390[];
extern char D_004BD398[];
extern char D_004BD3A0[];
extern char D_004BD3A8[];
static void * const dat_004938B0[8] = { (void*)0x0, (void*)D_004BD378, (void*)D_004BD380, (void*)D_004BD388, (void*)D_004BD390, (void*)D_004BD398, (void*)D_004BD3A0, (void*)D_004BD3A8 };

int func_003D7510(int arg0) {
    int var_a0;

    var_a0 = arg0;
    if (var_a0 < 0xA) {
        return F_(&(*(char*)dat_004938B0), (var_a0 * 4), int);
    }
    if (var_a0 < 0x64) {
        return *ScriptEnum_GetById();
    }
    if (var_a0 >= 0x13EC) {
        var_a0 -= 0x1388;
    }
    return *ScriptType_GetRecord(var_a0);
}
