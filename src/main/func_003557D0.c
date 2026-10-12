#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003557D0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(...); };
extern "C" {
int String_CtorCStr_13B480(...);                 
int func_00138B70(...);                            
int func_0013D680(...);                          
int func_00355490(...);                         
int func_00356CD0(...);                                  
void **func_0041DB80(...);                  
int func_00424820(...);                       
extern "C" char D_004BB098[];
extern "C" char D_004BB0A8[];
extern "C" char D_004BB0B8[];
extern "C" char D_004BB0C8[];
static void * const dat_00492C50[2] = { (void*)D_004BB098, (void*)0x0 };
static void * const dat_00492C58[2] = { (void*)D_004BB0A8, (void*)0x0 };
static void * const dat_00492C60[2] = { (void*)D_004BB0B8, (void*)0x0 };
static void * const dat_00492C68[2] = { (void*)D_004BB0C8, (void*)0x0 };
extern char D_004B88F0;
extern char D_004BB0F8;
}
extern "C" void func_003557D0(char * arg0) {
    int sp40[4];
    int sp30[4];
    void **temp_v1;
    void **var_s0;
    char * temp_a0;

    func_00356CD0();
    String_CtorCStr_13B480(sp40, &D_004BB0F8);
    func_0013D680(arg0 + 0x6C, sp40);
    func_00138B70(sp40, 0);
    String_CtorCStr_13B480(sp30, &D_004BB0F8);
    func_0013D680(arg0 + 0x78, sp30);
    func_00138B70(sp30, 0);
    F_(arg0, 0x84, signed char) = 0;
    F_(arg0, 0x88, int) = -1;
    F_(arg0, 0x8C, int) = 0;
    F_(arg0, 0x90, int) = 0;
    var_s0 = func_0041DB80(arg0, (*(int*)dat_00492C60));
    F_(arg0, 0x98, int) = (int)(((var_s0 != NULL) && (((VC003557D0 *)(var_s0))->v20(&D_004B88F0) != 0)) ? var_s0 : NULL);
    temp_v1 = (void **)(F_(arg0, 0x98, int));
    if (temp_v1 != NULL) {
        F_(temp_v1, 0x70, int) = 0x42B40000;
    }
    F_(arg0, 0x9C, int) = (int)(func_0041DB80(arg0, (*(int*)dat_00492C50)));
    F_(arg0, 0xA0, int) = (int)(func_0041DB80(arg0, (*(int*)dat_00492C58)));
    F_(arg0, 0xA4, int) = (int)(func_0041DB80(arg0, (*(int*)dat_00492C68)));
    F_(arg0, 0xF4, signed char) = 0;
    temp_a0 = (char *)(F_(arg0, 0x48, int));
    func_00424820(temp_a0, F_(temp_a0, 0x5C, int) - 2);
    func_00355490(arg0, 0);
}
