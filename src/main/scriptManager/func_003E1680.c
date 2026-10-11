#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_Load(int, int, int);                       
int func_003D7930(char *, int);                          
int func_003E11C0(char *, int, char *, int);                          
int func_003E12D0(char * , int);                     
extern char D_004BD890;
extern char D_004BD8A0;

int ScriptMgr_ReloadScript(char * arg0, int arg1) {
    int temp_v0;
    int temp_v0_2;
    int var_s0;

    temp_v0 = func_003E11C0(arg0, arg1, &D_004BD890, 0);
    func_003D7930(&D_004BD8A0, temp_v0);
    var_s0 = 0;
    temp_v0_2 = func_003E12D0(arg0, temp_v0);
    if (temp_v0_2 != 0) {
        var_s0 = Script_Load(temp_v0_2, F_(arg0, 0x4E90, int), 0) & 0xFF;
    }
    if (var_s0 != 0) {
        F_(arg0, 0x4EA0, int) = (int) (F_(arg0, 0x4EA0, int) + 1);
    }
    return var_s0 & 0xFF;
}
