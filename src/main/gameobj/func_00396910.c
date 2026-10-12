#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int func_0013B180(...);                          
int func_00396A90(...);                            
int func_00396AF0(...);                        
int func_00396B00(...);                          
int func_00396B10(...);                      
int func_00396C10(...);                            
int operator_delete(...);                             
extern unsigned char D_00533880;
}
#pragma inline_depth(10)
static inline void itb_(char **o, char *l) { int r; func_0013B180(&r, l); func_00396B10(o, &r); }
static inline void ite_(char **o, char *l) { int r; func_00396B00(&r, l); func_00396AF0(o, &r); }
extern "C" int func_00396910(int arg0, long long arg1) {
    int sp6C;
    char * sp68;
    int temp_s1;
    int sp5C;
    int temp_a0;
    char * var_s0;
    int sp60;

    if (arg0 != 0) {
        itb_((char **)&sp68, (char *)(arg0));
        var_s0 = sp68;
        while (ite_((char **)&sp6C, (char *)(arg0)), (int)var_s0 != (int)sp6C) {
                temp_s1 = F_(var_s0, 0x8, int);
                {
                    AllocGuard g;
                if (temp_s1 != 0) {
                    temp_a0 = temp_s1 + 4;
                    if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
                        func_00396C10(temp_a0, 0);
                    }
                }
                Mem_Free(0, temp_s1, "ska.icc", 0xCD);
                }
                var_s0 = (char *)(F_(var_s0, 0x4, int));
        }
        if (arg0 != 0) {
            func_00396A90(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
