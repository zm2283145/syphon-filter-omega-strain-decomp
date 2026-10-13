#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00292980 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
int atoi(...);                             
int String_CStr(...);                          
int GuiSaveAgentWidget_HandleEvent(...);                            
int func_00441CA0(...);                                
extern char D_004A9870;
}
extern "C" int func_00292980(char * arg0, void **arg1, int arg2) {
    void **var_s0;

    var_s0 = arg1;
    if ((arg2 & 0xFFFF) == 2) {
        var_s0 = ((var_s0 != NULL) && (((VC00292980 *)(var_s0))->v20(&D_004A9870) != 0)) ? var_s0 : NULL;
        if (var_s0 != NULL) {
            F_(arg0, 0x50, int) = atoi(String_CStr((char *)var_s0 + 4));
            F_(arg0, 0x4C, signed char) = 0;
            GuiSaveAgentWidget_HandleEvent(arg0);
        }
        return 1;
    }
    return func_00441CA0();
}
