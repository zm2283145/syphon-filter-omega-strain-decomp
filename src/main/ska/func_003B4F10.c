#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003B4F10 { virtual int v0(...); };
extern "C" {
int Alloc_Lock(...);                                    
int Alloc_Unlock(...);                                  
void **Mem_Alloc(...);                     
int Mem_Free(...);                     
int ModelNames_Insert(...);          
void **SkaClip_Construct(...);               
extern int D_004BCD60;
extern char D_004BCD70;
extern unsigned char D_00533880;
extern int D_00533888;
}
extern "C" void Skas_RegisterClip(int *arg0, int arg1, int arg2, int arg3) {
    int sp6C;
    void **var_s0;

    if (D_00533880 != 0) {
        Alloc_Lock(9);
    }
    D_00533888 += 1;
    var_s0 = Mem_Alloc(0, 0x50, &D_004BCD70, 0x216);
    if (D_00533880 != 0) {
        Alloc_Unlock(9);
    }
    D_00533888 -= 1;
    if (var_s0 != NULL) {
        var_s0 = SkaClip_Construct(var_s0, arg3);
    }
    ModelNames_Insert(&sp6C, arg1, arg2, var_s0);
    if (sp6C == D_004BCD60) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        ((VC003B4F10 *)(var_s0))->v0(-1);
        Mem_Free(0, var_s0, &D_004BCD70, 0x21C);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
    }
    *arg0 = sp6C;
}
