#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003EC300 { char vpad[20]; virtual int v0(); virtual int v1(); virtual int v2(...); };
extern "C" {
int List_Begin(...);                          
int func_003EC3B0(...);                        
int func_003EC3C0(...);                          
int func_003EC3D0(...);                      
extern char D_0055C0A8;
}
extern "C" void EffectService_DrawAll(void) {
    int sp2C;
    char * sp28;
    int sp24;
    int sp20;
    char * temp_a0;
    char * var_s0;

    List_Begin(&sp24, &D_0055C0A8);
    func_003EC3D0(&sp28, &sp24);
    var_s0 = sp28;
    func_003EC3C0(&sp20, &D_0055C0A8);
    func_003EC3B0(&sp2C, &sp20);
    if ((int)(var_s0) != (int)(sp2C)) {
        do {
            temp_a0 = (char *)(F_(var_s0, 0x8, int));
            ((VC003EC300 *)(temp_a0))->v2();
            var_s0 = (char *)(F_(var_s0, 0x4, int));
            func_003EC3C0(&sp20, &D_0055C0A8);
            func_003EC3B0(&sp2C, &sp20);
        } while ((int)(var_s0) != (int)(sp2C));
    }
}
