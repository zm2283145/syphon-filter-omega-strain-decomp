#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC0033D800 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(...); };
extern "C" {
int func_002C81D0(...);                               
int func_002C82F0(...);                               
int func_00414790(...);                                
void **func_004147A0(...);                             
int func_00418A80(...);                   
char * func_004294C0(...);                              
extern int D_004FFC04;
}
extern "C" void func_0033D800(char * arg0) {
    int temp_s0;
    void **temp_v0_2;
    char * temp_v0;

    temp_v0 = func_004294C0();
    if ((temp_v0 == NULL) || (F_(temp_v0, 0x255C, int) != 5)) {
        return;
    }
    func_002C82F0(D_004FFC04);
    temp_s0 = func_00418A80(func_00414790(), "GuiMissionSetup", "MSNSETUP");
    func_002C81D0(D_004FFC04);
    if (temp_s0 != 0) {
        F_(arg0, 0x14, unsigned short) = (unsigned short) (F_(arg0, 0x14, unsigned short) & 0xFFFD);
        temp_v0_2 = func_004147A0();
        ((VC0033D800 *)(temp_v0_2))->v23(temp_s0, 0x14);
    }
}
