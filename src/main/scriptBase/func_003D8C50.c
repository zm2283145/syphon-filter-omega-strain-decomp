#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int Alloc_Unlock(int);                                  
char * Mem_Alloc(int, int, char *, int);                      
int func_00290BB0(char *, int);                          
int func_003D7E90();                                  
int func_003D8E10(char * , void **);                   
int func_003D8E30(char * );                            
int func_003D8E80(char * , int, int);                    
int func_003D8EF0(char * , int, int);                    
int strrchr(char * , int);                             
extern char D_00499C71;
extern char D_004BD3B0;
extern unsigned char D_00533880;
extern int D_00533888;
extern char * D_00554F28;

#pragma push
#pragma opt_common_subs off
int Script_RegisterType(char * arg0, int arg1, signed char arg2, signed char arg3) {
    struct { int f60; int f64[2]; char * f6C; } sl;
    int temp_v0;
    char * temp_s0;
    char * var_s4;

    var_s4 = arg0;
    func_003D7E90();
    temp_v0 = strrchr(var_s4, 0x3A);
    if (temp_v0 != 0) {
        var_s4 = (char *)(temp_v0 + 1);
    }
    if ((F_(var_s4, 0x0, signed char) == 0x63) && (F_(&D_00499C71, F_(var_s4, 0x1, signed char), signed char) & 1)) {
        var_s4 += 1;
    }
    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    temp_s0 = Mem_Alloc(0, 0x50, &D_004BD3B0, 0x79);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (temp_s0 != NULL) {
        func_003D8EF0(temp_s0 + 4, func_00290BB0(sl.f64, 5), 1);
        func_003D8E80(temp_s0 + 0x14, func_00290BB0(&sl.f60, 5), 1);
        func_003D8E30(temp_s0 + 0x24);
        F_(temp_s0, 0x0, int) = (int)(var_s4);
        F_(temp_s0, 0x34, int) = arg1;
        F_(temp_s0, 0x3C, signed char) = 0;
        F_(temp_s0, 0x40, int) = -1;
        F_(temp_s0, 0x44, signed char) = 0;
        F_(temp_s0, 0x45, signed char) = arg2;
        F_(temp_s0, 0x48, int) = 0;
        F_(temp_s0, 0x4C, signed char) = arg3;
    }
    sl.f6C = temp_s0;
    F_(temp_s0, 0x38, int) = (int) (F_(D_00554F28, 0x4, int) + 0x64);
    F_(sl.f6C, 0x44, signed char) = 1;
    func_003D8E10(D_00554F28, &sl.f6C);
    return F_(sl.f6C, 0x38, int);
}
#pragma pop
