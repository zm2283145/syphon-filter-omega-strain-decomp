#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int *Mem_Alloc(...);                     
int func_003D6BE0(...);                   
int func_003DD9F0(...);                           
extern int D_004BD4C0;
extern unsigned char D_00533880;
extern int D_00555070;
}
extern "C" void func_003DC5A0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
int *var_s4;
int temp_s3;
int var_s2;
int *var_s1;
int temp_s5;
    int *var_s0;
    int temp_a1;
    int temp_v0;

    temp_s5 = arg4;
    var_s4 = (int *)(arg5);
    temp_s3 = func_003DD9F0(&D_00555070);
    if (temp_s5 != 0) {
        {
            AllocGuard g;
        var_s1 = Mem_Alloc(0, temp_s5 * 4, &D_004BD4C0, 0xB76);
        }
    } else {
        var_s1 = NULL;
    }
    for (var_s2 = 0; var_s2 < temp_s5; var_s2++) {
        temp_v0 = func_003D6BE0(temp_s3, var_s4[var_s2]);
        if (temp_v0 != NULL) {
            var_s1[var_s2] = F_(temp_v0, 0x4, int);
        } else if (arg2 != 0) {
            var_s1[var_s2] = 0;
        }
    }
    temp_a1 = arg7 * 4;
    *(int *)((char *)F_(arg0, 0x28, int) + temp_a1) = (int)(var_s1);
    *(int *)((char *)F_(arg0, 0x38, int) + temp_a1) = F_(temp_s3, 0x38, int);
}
