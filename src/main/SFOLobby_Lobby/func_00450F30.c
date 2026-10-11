#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00446560(char * , char * , int);               
int func_00449360(char * , int, int, char *);               
char * func_0044F290(char * );                        
int func_0044F2E0(char * , int);                       
extern char D_004C0F88;
extern char D_004C0F90;

int func_00450F30(char * arg0, int arg1, int arg2) {
    int temp_v1;
    char * temp_v0;

    if (arg1 < F_(arg0, 0x20, int)) {
        temp_v0 = func_0044F290(arg0 + 0x1C);
        temp_v1 = F_(temp_v0, 0x0, int);
        switch (temp_v1) {                          
        case 0:
            if (arg2 != 0) {
                func_00449360(arg0, F_(temp_v0, 0x8, int), 1, &D_004C0F88);
            } else {
                func_00449360(arg0, F_(temp_v0, 0x8, int), 2, &D_004C0F90);
            }
            break;
        case 1:
            func_00446560(arg0, temp_v0, arg2);
            break;
        }
        func_0044F2E0(arg0 + 0x1C, arg1);
    }
    return 1;
}
