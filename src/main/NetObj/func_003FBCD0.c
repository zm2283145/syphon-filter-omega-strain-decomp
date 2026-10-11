#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int, int, int);                          
int Alloc_Unlock(int);                                  
int Mem_Free(int, char *, char *, int);                         
int NetMap_Clear(int *);                              
int func_003FC080(char *);                               
int func_00436380(char *);                               
int func_00436BA0(char *, int);                            
int func_00436C00(char *);                               
int func_0043ACE0(char *);                               
int func_0043B190(char *);                               
extern signed char D_00493A10;
extern signed char D_00493A11;
extern signed char D_00493A12;
extern signed char D_00493A13;
extern char D_004BE228;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0055C770;
extern signed char D_0055C780;
extern signed char D_0055C781;
extern signed char D_0055C782;
extern signed char D_0055C783;
extern int D_0055C7A0;
extern char D_0055C7C0;
extern char *D_0055C988;
extern int D_0055C990;
extern int D_0055C9A0;
extern int D_0055C9A4;
extern int D_0055C9A8;
extern int D_0055C9AC;
extern int D_0055C9B0;

void NetSession_Cleanup(void) {
    int sp2C;
    int sp28;
    char *temp_s0;
    char *var_a0;
    char *var_v1;
    int var_a1;
    int var_a2;

    D_0055C990 = 0;
    if (D_0055C7A0 > 0) {
        NetMap_Clear(&D_0055C7A0);
    }
    func_003FC080(&D_0055C770);
    func_00436C00(&sp2C);
    func_00436380(&sp2C);
    func_0043B190(&sp28);
    func_0043ACE0(&sp28);
    var_a2 = 0;
    var_a0 = &D_0055C7C0;
    do {
        F_(var_a0, 0x14, signed char) = 0;
        F_(var_a0, 0x18, int) = 0;
        var_a1 = 0;
        F_(var_a0, 0x94, short) = 0;
        var_v1 = var_a0;
loop_4:
        F_(var_v1, 0x1C, int) = 0;
        F_(var_v1, 0x20, int) = 0;
        var_a1 += 6;
        F_(var_v1, 0x24, int) = 0;
        F_(var_v1, 0x28, int) = 0;
        F_(var_v1, 0x2C, int) = 0;
        F_(var_v1, 0x30, int) = 0;
        var_v1 += 0x18;
        if (var_a1 < 0x1E) {
            goto loop_4;
        }
        var_a2 += 1;
        var_a0 += 0x98;
    } while (var_a2 < 3);
    temp_s0 = D_0055C988;
    if (temp_s0 != NULL) {
        if (D_00533880 != 0) {
            Alloc_Lock(9, var_a1, var_a2);
        }
        D_00533888 += 1;
        func_00436BA0(temp_s0, -1);
        Mem_Free(0, temp_s0, &D_004BE228, 0x12E);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_0055C988 = NULL;
        D_00533888 -= 1;
    }
    D_0055C780 = 0;
    D_0055C781 = 0;
    D_0055C782 = 0;
    D_0055C783 = 0;
    D_00493A10 = 2;
    D_00493A11 = 2;
    D_00493A12 = 2;
    D_00493A13 = 2;
    D_0055C9A0 = 0;
    D_0055C9A4 = 0;
    D_0055C9A8 = 0;
    D_0055C9AC = 0;
    D_0055C9B0 = 0;
    func_00436BA0(&sp2C, -1);
}
