#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __construct_array(char *, char *, char *, int, int);              
int __register_global_object(char *, char *, char *);          
extern char D_00571DB0;
extern char D_00571DC0;
extern int D_00571FA0;
extern int D_00571FA4;
extern int D_00571FA8;
extern int D_00571FAC;
extern char InterfaceMgr_dtor;
extern char func_00413EA0;
extern char func_00413F00;

void func_004D7040(void) {
    char *var_s0;
    int var_v1;

    var_s0 = &D_00571DC0;
    __construct_array(&D_00571DC0, &func_00413F00, &func_00413EA0, 0x18, 20);
    var_v1 = 0;
    D_00571FA0 = 0;
    D_00571FA4 = 0;
    D_00571FA8 = 0;
    D_00571FAC = 0;
    do {
        F_(var_s0, 0xC, int) = 0;
        F_(var_s0, 0x10, int) = 0;
        var_v1 += 5;
        F_(var_s0, 0x24, int) = 0;
        F_(var_s0, 0x28, int) = 0;
        F_(var_s0, 0x3C, int) = 0;
        F_(var_s0, 0x40, int) = 0;
        F_(var_s0, 0x54, int) = 0;
        F_(var_s0, 0x58, int) = 0;
        F_(var_s0, 0x6C, int) = 0;
        F_(var_s0, 0x70, int) = 0;
        var_s0 += 0x78;
    } while (var_v1 < 0x14);
    __register_global_object(&D_00571DC0, &InterfaceMgr_dtor, &D_00571DB0);
}
