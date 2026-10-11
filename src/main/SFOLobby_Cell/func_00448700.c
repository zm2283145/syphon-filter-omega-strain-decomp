#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_004505C0();                                
int func_00451B00(char * , int, char *, int);                 
extern char D_004C0D10;
extern char * D_00585E60;

void func_00448700(int d0, int d1, int d2, char * arg3) {
    int temp_a0;

    if (func_004505C0() == 0) {
        temp_a0 = F_(arg3, 0x18, int);
        switch (temp_a0) {                          
        case 0:
            break;
        default:
        case -991:
        case -989:
        case -988:
        case -990:
            func_00451B00(D_00585E60, 1, &D_004C0D10, 0x82A);
            break;
        }
        F_(D_00585E60, 0x220, int) = 1;
    }
}
