#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                      
int Script_Load(char * , int, int);                  
int func_001C07C0(char * );                            
int func_003983E0(char * );                            
int Script_PrintWarning(char *, int);                          
int func_003D8E30(char * );                            
int func_003E11C0(char * , int, char *, int);               
int func_003E12D0();                                
int func_003E1900(char * , void **);                   
int func_003E1930(char * );                            
int func_003E1980(char * );                            
int func_003E19D0(char * );                            
extern char D_004BD4C0;
extern char D_004BD890;
extern unsigned char D_00533880;
extern int D_00533888;

int ScriptMgr_LoadScript(char * arg0, int arg1, int arg2) {
    char * sp5C;
    int temp_s0;
    unsigned char var_s2;
    char * temp_s2;

    var_s2 = 1;
    if (func_003E12D0() == 0) {
        temp_s0 = func_003E11C0(arg0, arg1, &D_004BD890, arg2);
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        temp_s2 = Mem_Alloc(0, 0x90, &D_004BD4C0, 0x144);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (temp_s2 != NULL) {
            func_003E19D0(temp_s2);
            func_003E1980(temp_s2 + 0x10);
            func_003983E0(temp_s2 + 0x20);
            func_003D8E30(temp_s2 + 0x30);
            func_003D8E30(temp_s2 + 0x40);
            func_003E1930(temp_s2 + 0x50);
            func_001C07C0(temp_s2 + 0x60);
            func_001C07C0(temp_s2 + 0x70);
            F_(temp_s2, 0x88, int) = 0;
            F_(temp_s2, 0x84, int) = 0;
        }
        sp5C = temp_s2;
        var_s2 = Script_Load(temp_s2, F_(arg0, 0x4E90, int), temp_s0);
        func_003E1900(arg0 + 0xC, &sp5C);
        if (var_s2) Script_PrintWarning("loaded %s...", temp_s0); else Script_PrintWarning("couldn't load script %s...", temp_s0);
    }
    return var_s2;
}
