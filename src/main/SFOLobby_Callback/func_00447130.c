#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int String_Copy(char *, char * );                         
int func_0044F470(int, char *);                          
int func_004505C0();                                
int memcpy(char * , char * , int);                        
extern char * D_00585E60;

void func_00447130(int d0, int d1, int d2, char * arg3) {
    int sp20[64];

    if (func_004505C0() == 0) {
        F_(D_00585E60, 0x19C, int) = 1;
        if (F_(arg3, 0x18, int) == 0) {
            String_Copy(sp20, arg3 + 0x1C);
            func_0044F470(F_(D_00585E60, 0x2404, int), sp20);
        }
        memcpy(D_00585E60 + 0x17CC, arg3, 0x120);
    }
}
