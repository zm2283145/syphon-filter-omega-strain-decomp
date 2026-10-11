#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00138B70(char * , int);                         
int func_0013A040(char * , int);                         
int func_0041F370(char **, int);                           
int operator_delete(char **);                            
extern char D_004E1620;

char **func_0045BC10(char **arg0, long long arg1) {
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_a0 = (char *)arg0 + 0x80;
        *arg0 = &D_004E1620;
        if (temp_a0 != NULL) {
            func_0013A040(temp_a0, -1);
        }
        temp_a0_2 = (char *)arg0 + 0x70;
        if (temp_a0_2 != NULL) {
            func_0013A040(temp_a0_2, -1);
        }
        temp_a0_3 = (char *)arg0 + 0x58;
        if (temp_a0_3 != NULL) {
            func_00138B70(temp_a0_3, 0);
        }
        func_0041F370(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
