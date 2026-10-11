#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_00450CF0();                                
int func_00451200(char *, int);                          
void *memcpy(void *, void *, int);                                

int func_00450C60(char *arg0, int arg1, char *arg2) {
    if (func_00450CF0() != 0) {
        return 1;
    }
    if (func_00451200(arg0, arg1) == 0) {
        return 0;
    }
    memcpy(arg2, arg0 + 0xAD0, 0xFC);
    return 1;
}
