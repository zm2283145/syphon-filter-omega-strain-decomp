#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Dtor(char * , int);                         
int func_0013A040(char * , int);                         
int func_0041F370(char **, int);                           
int operator_delete(char **);                            
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041D8C0();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041EBF0();
extern void func_0041EFA0();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F210();
extern void func_0045BCC0();
extern void func_0045BCD0();
extern void func_0045D3D0();
extern void func_0045D420();
extern void func_0045D8D0();
extern void func_0045D960();
extern void func_0045DE80();
extern void func_0045DFD0();
extern void * const D_004E1620[];

char **func_0045BC10(char **arg0, long long arg1) {
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_a0 = (char *)arg0 + 0x80;
        *arg0 = &(*(char*)D_004E1620);
        if (temp_a0 != NULL) {
            func_0013A040(temp_a0, -1);
        }
        temp_a0_2 = (char *)arg0 + 0x70;
        if (temp_a0_2 != NULL) {
            func_0013A040(temp_a0_2, -1);
        }
        temp_a0_3 = (char *)arg0 + 0x58;
        if (temp_a0_3 != NULL) {
            String_Dtor(temp_a0_3, 0);
        }
        func_0041F370(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E1620[24] = { (void*)0x0, (void*)0x0, (void*)func_0045BC10, (void*)func_0045DFD0, (void*)func_0045DE80, (void*)func_0041F080, (void*)func_0041F070, (void*)func_0041EFA0, (void*)func_0041EBF0, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_0045D420, (void*)func_0045D8D0, (void*)func_0041E230, (void*)func_0045D960, (void*)func_0045D3D0, (void*)func_0041F210, (void*)func_0041D8C0, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_0045BCC0, (void*)func_0045BCD0, (void*)0x0 };
