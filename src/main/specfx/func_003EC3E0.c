#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003EC3E0 { char vpad[20]; virtual int v0(...); };
extern "C" {
int func_00138DA0(...);                     
int func_0013B180(...);                          
int func_0015AF40(...);                      
int func_003EC3B0(...);                        
int func_003EC3C0(...);                          
int func_003EC3D0(...);                      
extern char D_0055C0A8;
}
extern "C" void func_003EC3E0(void) {
    int sp3C;
    char * sp38;
    char * sp34;
    int sp30;
    int sp2C;
    int sp28;
    int sp24;
    char * temp_a0;
    char * temp_v0;
    char * var_s0;

    func_0013B180(&sp28, &D_0055C0A8);
    func_003EC3D0(&sp38, &sp28);
    var_s0 = sp38;
    func_003EC3C0(&sp24, &D_0055C0A8);
    func_003EC3B0(&sp3C, &sp24);
    if ((int)(var_s0) != (int)(sp3C)) {
        do {
            temp_a0 = (char *)(F_(var_s0, 0x8, int));
            if (temp_a0 != NULL) {
                ((VC003EC3E0 *)(temp_a0))->v0(1);
            }
            temp_v0 = var_s0;
            var_s0 = (char *)(F_(var_s0, 0x4, int));
            sp34 = temp_v0;
            func_0015AF40(&sp2C, &sp34);
            func_00138DA0(&sp30, &D_0055C0A8, &sp2C);
            func_003EC3C0(&sp24, &D_0055C0A8);
            func_003EC3B0(&sp3C, &sp24);
        } while ((int)(var_s0) != (int)(sp3C));
    }
}
