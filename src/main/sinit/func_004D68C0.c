#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(int *, char *, char *);        
int func_003D18D0(char *);                               
extern char D_0055A340;
extern char D_0055A6C0;
extern char D_0055A700;
extern char D_0055A820;
extern int D_0055A830;
extern signed char D_0055A834;
extern int D_0055A838;
extern signed char D_0055A83C;
extern char func_003EA340;

void func_004D68C0(void) {
    char *var_v1;

    var_v1 = &D_0055A340;
    do {
        F_(var_v1, 0x12C, int) = 0;
        F_(var_v1, 0x130, int) = 0;
        F_(var_v1, 0x134, int) = 0;
        F_(var_v1, 0x138, int) = 0;
        F_(var_v1, 0x13C, int) = 0;
        F_(var_v1, 0x140, int) = 0;
        F_(var_v1, 0x144, int) = 0;
        F_(var_v1, 0x148, int) = 0;
        var_v1 += 0x1C0;
    } while (var_v1 != &D_0055A6C0);
    func_003D18D0(&D_0055A700);
    D_0055A834 = 0;
    D_0055A83C = 0;
    D_0055A830 = 0;
    D_0055A838 = 0;
    __register_global_object(&D_0055A830, &func_003EA340, &D_0055A820);
}
