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
int func_00138B70(...);                         
int func_00177B80(...);                            
int func_002731D0(...);                          
int func_002731E0(...);                      
int func_002731F0(...);                          
int func_002740F0(...);                            
int func_00274170(...);                            
int func_003E9770(...);                               
int operator_delete(...);                             
extern unsigned char D_0048B308;
extern char D_004A8F60;
extern unsigned char D_00533880;
}
#pragma inline_depth(10)
static inline void beg0(char **o, char *l) { int r; func_002731F0(&r, l); func_002731E0(o, &r); }
static inline void end0(char **o, char *l) { int r; func_002731D0(&r, l); func_002731E0(o, &r); }
static inline void beg1(char **o, char *l) { beg0(o, l); }
static inline void end1(char **o, char *l) { end0(o, l); }
static inline void beg2(char **o, char *l) { beg1(o, l); }
static inline void end2(char **o, char *l) { end1(o, l); }
static inline void end3(char **o, char *l) { end2(o, l); }
extern "C" int func_00273F00(char *arg0, long long arg1) {
    char * sp6C;
    char * temp_s1;
    char * sp68;
    int temp_a0_4;
    char * temp_a0;
    char * var_s0;
    int temp_a0_5;
    int temp_a0_3;
    int sp5C;
    char * temp_a0_2;
    int sp60;

    if (arg0 != 0) {
        D_0048B308 = 0;
        beg0(&sp6C, arg0 + 0xC);
        var_s0 = sp6C;
        for (; end0(&sp68, arg0 + 0xC), var_s0 != sp68; ) {
                temp_s1 = (char *)(F_(var_s0, 0x8, int));
                {
                    AllocGuard g;
                if (temp_s1 != NULL) {
                    if (D_0048B308 != 0) {
                        func_003E9770(F_(temp_s1, 0x8, int));
                        func_003E9770(F_(temp_s1, 0x4, int));
                    }
                    temp_a0 = temp_s1 + 0x28;
                    if (temp_a0 != NULL) {
                        func_00138B70(temp_a0, 0);
                    }
                    temp_a0_2 = temp_s1 + 0x1C;
                    if (temp_a0_2 != NULL) {
                        func_00138B70(temp_a0_2, 0);
                    }
                }
                Mem_Free(0, temp_s1, &D_004A8F60, 0x17E);
                }
                var_s0 = (char *)(F_(var_s0, 0x4, int));
        }
        temp_a0_3 = (int)(arg0 + 0x24);
        if (temp_a0_3 != 0) {
            func_00274170(temp_a0_3, 0);
        }
        temp_a0_4 = (int)(arg0 + 0x18);
        if (temp_a0_4 != 0) {
            func_00177B80(temp_a0_4, 0);
        }
        temp_a0_5 = (int)(arg0 + 0xC);
        if (temp_a0_5 != 0) {
            func_00274170(temp_a0_5, 0);
        }
        if (arg0 != 0) {
            func_002740F0(arg0, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return (int)(arg0);
}
