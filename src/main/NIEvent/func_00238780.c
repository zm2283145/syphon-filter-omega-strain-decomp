#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cGOBJ_dtor(char **, int);                              
int func_00238850(char * , int);                         
int func_00240390(char * , int);                         
int func_00240480(int, int);                            
int operator_delete(char **);                            
extern char D_004DC190;

char **func_00238780(char **arg0, long long arg1) {
    int temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_a0 = (int)((char *)arg0 + 0xC4);
        *arg0 = &D_004DC190;
        if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
            func_00240480(temp_a0, 0);
        }
        temp_a0_2 = (char *)arg0 + 0xAC;
        if ((temp_a0_2 != NULL) && (temp_a0_2 != NULL) && (temp_a0_2 != NULL)) {
            func_00240390(temp_a0_2, 0);
        }
        temp_a0_3 = (char *)arg0 + 0x9C;
        if (temp_a0_3 != NULL) {
            func_00238850(temp_a0_3, -1);
        }
        cGOBJ_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
