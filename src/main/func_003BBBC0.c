#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_0036E220(char *, int);                            
int func_0036E4B0(char *, char *, int, int);                    
int func_0037B2F0(char *, int, int);                       
int func_003EAA60(int, char *, int);                       
int func_003EBA50();                                
int operator_delete(char * );                          
int sprintf(char *, char *, char * );                        
extern char D_004BD018;
extern char D_005381F0;

char * func_003BBBC0(char * arg0, short arg1) {
    int spD0[32];
    int sp30[40];
    int temp_v1;

    if (arg0 != NULL) {
        temp_v1 = F_(arg0, 0x48, int);
        if (temp_v1 & 0x1000) {
            if (temp_v1 & 0x2000) {
                sprintf(spD0, &D_004BD018, arg0);
                func_0036E4B0(sp30, spD0, 0, 0);
                func_003EAA60(func_003EBA50(), sp30, 1);
                func_0036E220(sp30, -1);
            } else {
                func_0037B2F0(&D_005381F0, F_(arg0, 0x44, int), -1);
            }
        }
        if (arg1 > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
