#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0035D1F0(char **, int);                           
int func_0036E220(char * , int);                         
int func_00461DC0(char * , int);                         
int operator_delete(char **);                            
extern void func_0035BF70();
extern void func_0035CD00();
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041EBF0();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F090();
extern void func_0041F210();
extern void func_00463120();
extern void func_00463130();
extern void func_00463160();
extern void func_004637D0();
extern void func_00463940();
extern void func_00463980();
extern void func_00463A20();
extern void * const D_004E1840[];

#pragma push
#pragma opt_common_subs off
char **func_00463060(char **arg0, long long arg1) {
    char * temp_a0;

    if (arg0 != NULL) {
        *arg0 = &(*(char*)D_004E1840);
        if (((char *)arg0 + 0x260) != 0) {
            if (((char *)arg0 + 0x280) != NULL) {
                func_0036E220((char *)arg0 + 0x364, -1);
                func_0036E220((char *)arg0 + 0x2C8, -1);
            }
            temp_a0 = (char *)arg0 + 0x260;
            if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
                func_00461DC0(temp_a0, 0);
            }
        }
        func_0035D1F0(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}

#pragma pop
void * const D_004E1840[24] = { (void*)0x0, (void*)0x0, (void*)func_00463060, (void*)func_0035CD00, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00463A20, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_00463160, (void*)func_0035BF70, (void*)func_0041E230, (void*)func_004637D0, (void*)func_00463980, (void*)func_0041F210, (void*)func_00463940, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00463120, (void*)func_00463130, (void*)0x0 };
