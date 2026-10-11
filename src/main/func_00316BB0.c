#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMsg_RegisterType(char *, int, char *);               
int func_002E9A10();                                
int func_002E9A98(char *, char *, int, int);                  
int func_003C9C30(char *);                             
extern char D_0052ACD0;
extern char func_00316D10;

unsigned char func_00316BB0(void) {
    struct { int f20[2]; int f28; int f2C; int f30; int f34[3]; } sl;
    unsigned char var_s0;

    var_s0 = 0;
    if ((func_002E9A10() == 0) && (func_003C9C30(sl.f20) != 0) && (func_002E9A98(sl.f20, &sl.f30, 1, 1) == 0) && (func_002E9A98(sl.f20, sl.f34, 4, 1) == 0) && (func_002E9A98(sl.f20, &sl.f28, 1, 1) == 0) && (func_002E9A98(sl.f20, &sl.f2C, 4, 1) == 0) && (NetMsg_RegisterType(&D_0052ACD0, 2, &func_00316D10) == 0)) {
        var_s0 = 1;
    }
    return var_s0;
}
