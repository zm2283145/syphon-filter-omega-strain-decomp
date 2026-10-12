#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00242900 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(...); };
extern "C" {
int func_00131470(...);                            
int func_0036A240(...);                               
int func_00414790(...);                                
void **func_004147A0(...);                             
int func_00418980(...);                        
extern char D_004FFB50;
extern unsigned char D_004FFBB7;
extern char D_0055A300;
}
#pragma push
#pragma opt_common_subs off
extern "C" void func_00242900(char * arg0) {
    int temp_v0;
    int temp_v0_3;
    void **temp_v0_2;
    void **temp_v0_4;

    if (F_(arg0, 0x6A8, unsigned char) != 0) {
        temp_v0 = func_00418980(func_00414790(), "GuiStartMenu");
        if (temp_v0 != 0) {
            temp_v0_2 = func_004147A0();
            ((VC00242900 *)(temp_v0_2))->v24(temp_v0);
        }
        temp_v0_3 = func_00418980(func_00414790(), "GuiStartMenuBackdrop");
        if (temp_v0_3 != 0) {
            temp_v0_4 = func_004147A0();
            ((VC00242900 *)(temp_v0_4))->v24(temp_v0_3);
        }
        func_0036A240(&D_0055A300);
        if (D_004FFBB7 != 0) {
            func_00131470(&D_004FFB50, 0);
        }
        F_(arg0, 0x6A8, unsigned char) = 0U;
    }
}
#pragma pop
