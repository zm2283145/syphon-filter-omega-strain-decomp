#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0044F470(int, char * );                       
int func_004505C0();                                
int memcpy(char * , char * , int);                        
int strcmp(char * , char *);                            
extern char D_004C0CE8;
extern char * D_00585E60;

void func_004473C0(int d0, int d1, int d2, char * arg3) {
    if (func_004505C0() == 0) {
        F_(D_00585E60, 0x1B8, int) = 1;
        if (F_(arg3, 0x18, int) != 0) {
            F_(arg3, 0x11C, signed char) = 1;
        } else if (strcmp(arg3, &D_004C0CE8) == 0) {
            func_0044F470(F_(D_00585E60, 0x23F8, int), arg3 + 0x1C);
        } else {
            func_0044F470(F_(D_00585E60, 0x23FC, int), arg3 + 0x1C);
        }
        memcpy(D_00585E60 + 0x484, arg3, 0x120);
    }
}
