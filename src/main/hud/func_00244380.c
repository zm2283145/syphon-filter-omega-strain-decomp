#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
char **Mem_Alloc(...);                        
int func_003E8EB0(...);                            
int func_003E9770(...);                              
int func_003E97B0(...);                      
int func_003E99B0(...);                   
char * func_003EF010(...);                           
extern char D_004A7210;
extern char D_004E0480;
extern unsigned char D_00533880;
typedef struct { char p0[92]; int f5C; int f60; int f64; int f68; } PS0_00244380;
}
extern "C" void func_00244380(PS0_00244380 *arg0, int arg1, int arg2) {
    char **temp_a0;
    char **temp_s0;
    char **temp_s0_2;
    int var_s0;
    char * temp_v1;

    if (arg2 == -1) {
        var_s0 = arg0->f5C;
    } else {
        var_s0 = arg0->f60;
    }
    temp_v1 = (char *)(arg0->f68);
    if (temp_v1 == NULL) {
        arg0->f68 = (int)(func_003EF010(var_s0));
        {
            AllocGuard g;
        temp_s0 = Mem_Alloc(0, 0x90, &D_004A7210, 0x3A1);
        }
        if (temp_s0 != NULL) {
            func_003E99B0(temp_s0, arg0->f68, arg1);
            *temp_s0 = &D_004E0480;
        }
        arg0->f64 = (int)(temp_s0);
    } else if (F_(temp_v1, 0x70, int) != var_s0) {
        temp_a0 = (char **)(arg0->f64);
        if (temp_a0 != NULL) {
            func_003E9770(temp_a0);
        } else {
            func_003E8EB0(temp_v1);
        }
        arg0->f68 = (int)(func_003EF010(var_s0));
        {
            AllocGuard g;
        temp_s0_2 = Mem_Alloc(0, 0x90, &D_004A7210, 0x3AD);
        }
        if (temp_s0_2 != NULL) {
            func_003E99B0(temp_s0_2, arg0->f68, arg1);
            *temp_s0_2 = &D_004E0480;
        }
        arg0->f64 = (int)(temp_s0_2);
    }
    func_003E97B0(arg0->f64, arg1, arg2);
}
