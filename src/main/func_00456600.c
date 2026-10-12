#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00456600 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
int Loc_LookupText(...);                             
int func_0041BEB0(...);                   
void **func_0041DB80(...);                          
int sprintf(...);                           
extern int D_004A7520;
extern int D_004C1A38;
extern int D_004C1C60;
extern int D_004C1C70;
}
extern "C" void func_00456600(int arg0, int arg1) {
    int sp30[4];
    int temp_v0;
    void **var_s0;

    F_(arg0, 0xB0, int) = arg1;
    var_s0 = func_0041DB80(arg0, &D_004C1C60);
    var_s0 = ((var_s0 != NULL) && (((VC00456600 *)(var_s0))->v20(&D_004A7520) != 0)) ? var_s0 : NULL;
    if (var_s0 != NULL) {
        sprintf(sp30, &D_004C1C70, arg1);
        temp_v0 = Loc_LookupText(sp30);
        if (temp_v0 != NULL) {
            func_0041BEB0(var_s0, temp_v0, 0);
            return;
        }
        func_0041BEB0(var_s0, &D_004C1A38, 0);
    }
}
