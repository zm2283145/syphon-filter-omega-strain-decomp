#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(char *, char *, char *);          
int func_00431320(char *, char *, char *);                     
int func_00431340(char *, char *, char *);                     
int func_00431360(char *, char *, char *);                     
int func_00431380(char *, char *, char *);                     
int func_004313A0(char *, char *, char *);                     
extern char D_00582690;
extern char D_005826A0;
extern char D_005826B0;
extern char D_005826C0;
extern char D_005826D0;
extern char D_005826E0;
extern char D_005826F0;
extern char D_00582700;
extern char D_00582710;
extern char D_00582720;
extern char *D_00582730;
extern char func_00431540;
extern char func_004315A0;
extern char func_00431600;
extern char func_00431660;
extern char func_004316F0;

void StaticInit_RegisterSwitchControllersMsg(void) {
    int sp3C;
    int sp38;
    int sp34;
    int sp30;
    int sp2C;
    int sp28;
    int sp24;
    int sp20;
    int sp1C;
    int sp18;

    func_00431320(&D_005826A0, &sp34, &sp30);
    __register_global_object(&D_005826A0, &func_004316F0, &D_00582690);
    func_00431340(&D_005826C0, &sp3C, &sp38);
    __register_global_object(&D_005826C0, &func_00431660, &D_005826B0);
    func_00431360(&D_005826E0, &sp2C, &sp28);
    __register_global_object(&D_005826E0, &func_00431600, &D_005826D0);
    func_00431380(&D_00582700, &sp24, &sp20);
    __register_global_object(&D_00582700, &func_004315A0, &D_005826F0);
    func_004313A0(&D_00582720, &sp1C, &sp18);
    __register_global_object(&D_00582720, &func_00431540, &D_00582710);
    D_00582730 = "cSwitchControllersMsg";
}
