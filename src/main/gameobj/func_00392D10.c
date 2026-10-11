#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int func_0013B180(...);                          
int func_001BFA50(...);                            
int func_001BFBB0(...);                            
int func_00392F50(...);                            
int func_00392FD0(...);                        
int func_00392FE0(...);                          
int func_00392FF0(...);                      
int func_003961E0(...);                            
int func_00396620(...);                            
int operator_delete(...);                             
extern char D_004BC520;
extern unsigned char D_00533880;
}
#pragma inline_depth(10)
static inline void itb_(char **o, char *l) { int r; func_0013B180(&r, l); func_00392FF0(o, &r); }
static inline void ite_(char **o, char *l) { int r; func_00392FE0(&r, l); func_00392FD0(o, &r); }
extern "C" int func_00392D10(char *arg0, long long arg1) {
    int temp_a0_4;
    int temp_a0_6;
    int temp_a0_2;
    int sp6C;
    int temp_s3;
    int temp_a0_3;
    char * sp68;
    char * var_s0;
    int sp5C;
    int temp_a0_5;
    int sp60;
    int temp_a0;

    if (arg0 != 0) {
        itb_((char **)&sp68, (char *)(arg0 + 0x6C));
        var_s0 = sp68;
        while (ite_((char **)&sp6C, (char *)(arg0 + 0x6C)), (int)var_s0 != (int)sp6C) {
                temp_s3 = F_(var_s0, 0x8, int);
                {
                    AllocGuard g;
                Mem_Free(0, temp_s3, &D_004BC520, 0x423);
                }
                var_s0 = (char *)(F_(var_s0, 0x4, int));
        }
        temp_a0 = (int)(arg0 + 0xA0);
        if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
            func_003961E0(temp_a0, 0);
        }
        temp_a0_2 = (int)(arg0 + 0x88);
        if ((temp_a0_2 != 0) && (temp_a0_2 != 0) && (temp_a0_2 != 0)) {
            func_001BFBB0(temp_a0_2, 0);
        }
        temp_a0_3 = (int)(arg0 + 0x78);
        if ((temp_a0_3 != 0) && (temp_a0_3 != 0) && (temp_a0_3 != 0) && (temp_a0_3 != 0)) {
            func_001BFA50(temp_a0_3, 0);
        }
        temp_a0_4 = (int)(arg0 + 0x6C);
        if (temp_a0_4 != 0) {
            func_00392F50(temp_a0_4, 0);
        }
        temp_a0_5 = (int)(arg0 + 0x54);
        if ((arg0 + 0x24) != 0) {
            if ((temp_a0_5 != 0) && (temp_a0_5 != 0) && (temp_a0_5 != 0)) {
                func_00396620(temp_a0_5, 0);
            }
            temp_a0_6 = (int)(arg0 + 0x3C);
            if ((temp_a0_6 != 0) && (temp_a0_6 != 0) && (temp_a0_6 != 0)) {
                func_00396620(temp_a0_6, 0);
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (int)(arg0);
}
