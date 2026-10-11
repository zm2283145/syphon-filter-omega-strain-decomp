#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC002955B0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(...); };
extern "C" {
char * Agent_GetSelected(...);                    
int func_00441A10(...);                            
extern char D_004FFB50;
}
extern "C" void func_002955B0(char * arg0) {
    int var_v1;
    char * temp_v0;

    F_(arg0, 0x2F4, signed char) = 1;
    temp_v0 = Agent_GetSelected(&D_004FFB50, -1);
    var_v1 = F_(temp_v0, 0xB73, unsigned char) != 0;
    if (var_v1 == 0) {
        var_v1 = F_(temp_v0, 0xB72, unsigned char) != 0;
    }
    if (var_v1 != 0) {
        F_(arg0, 0x4C, signed char) = 2;
        func_00441A10(arg0);
        return;
    }
    ((VC002955B0 *)(arg0))->v21(1);
}
