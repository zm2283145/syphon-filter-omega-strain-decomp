#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int *ScriptEnum_GetById();                          
int *func_003D7590(int);                            
extern char D_004938B0;

int func_003D7510(int arg0) {
    int var_a0;

    var_a0 = arg0;
    if (var_a0 < 0xA) {
        return F_(&D_004938B0, (var_a0 * 4), int);
    }
    if (var_a0 < 0x64) {
        return *ScriptEnum_GetById();
    }
    if (var_a0 >= 0x13EC) {
        var_a0 -= 0x1388;
    }
    return *func_003D7590(var_a0);
}
