#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char * Mem_Alloc(...);                      
int Mem_Free(...);                       
int func_00138DA0(...);                     
                          
int func_0015AF40(...);                      
                        
                          
                      
int func_00434BB0(...);                      
extern char D_004BFCA0;
extern unsigned char D_00533880;
extern char D_00582AB0;
extern char D_00582AD0;
}
struct Raw_4E20 { int p; Raw_4E20() {} };
extern "C" Raw_4E20 func_0013B180(void*);
extern "C" Raw_4E20 func_00432730(void*);
extern "C" void func_00432740(char**, const Raw_4E20&);
extern "C" void func_00432720(char**, const Raw_4E20&);
static inline void Begin_4E20(char** out) { func_00432740(out, func_0013B180(&D_00582AB0)); }
static inline void End_4E20(char** out) { func_00432720(out, func_00432730(&D_00582AB0)); }


extern "C" void func_00434E20(int d0, char * arg1) {
    char * sp7C;
    char * sp78;
    char * temp_s0;
    {
        AllocGuard g;
    temp_s0 = Mem_Alloc(0, 0x14, &D_004BFCA0, 0x2D5);
    }
    if (temp_s0 != NULL) {
        F_(temp_s0, 0x4, unsigned char) = F_(arg1, 0x4, unsigned char);
        F_(temp_s0, 0x0, int) = F_(arg1, 0x0, int);
        F_(temp_s0, 0x5, unsigned char) = F_(arg1, 0x5, unsigned char);
        F_(temp_s0, 0x6, unsigned char) = F_(arg1, 0x6, unsigned char);
        F_(temp_s0, 0xA, unsigned char) = F_(arg1, 0xA, unsigned char);
        F_(temp_s0, 0x7, unsigned char) = F_(arg1, 0x7, unsigned char);
        F_(temp_s0, 0xB, unsigned char) = F_(arg1, 0xB, unsigned char);
        F_(temp_s0, 0x8, unsigned char) = F_(arg1, 0x8, unsigned char);
        F_(temp_s0, 0xC, unsigned char) = F_(arg1, 0xC, unsigned char);
        F_(temp_s0, 0x9, unsigned char) = F_(arg1, 0x9, unsigned char);
        F_(temp_s0, 0xD, unsigned char) = F_(arg1, 0xD, unsigned char);
        F_(temp_s0, 0x10, int) = F_(arg1, 0x10, int);
    }
    sp7C = temp_s0;
    func_00434BB0(&D_00582AD0, &sp7C);
    {
    char * sp70;
    int * temp_s2;
    char * temp_s0_2;
    char * var_s1;
    Begin_4E20(&sp70);
    var_s1 = sp70;
    while ((End_4E20(&sp78), (int)(var_s1) != (int)(sp78))) {
            temp_s2 = (int *)(F_(var_s1, 0x8, int));
            char * temp_s0_2 = var_s1;
            var_s1 = (char *)(F_(var_s1, 0x4, int));
            if (*temp_s2 == F_(arg1, 0x0, int)) {
                {
                    AllocGuard g;
                Mem_Free(0, temp_s2, &D_004BFCA0, 0x2E6);
                }
                {
                char * sp68;
                int sp64;
                int sp60;
                sp68 = temp_s0_2;
                func_0015AF40(&sp60, &sp68);
                func_00138DA0(&sp64, &D_00582AB0, &sp60);
                }
            }
    }

    }
}