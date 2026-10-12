#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int ScalarCollection_Init(char *);                       
int __register_global_object(char *, char *, char *);          
int func_0043B9E0(char *, char *, char *);                     
extern char D_005838A8;
extern char D_005838B8;
extern char D_005838C8;
extern char D_005838D8;
extern char D_005838E8;
extern char D_00583900;
extern char func_0043BA60;
extern char func_0043BAC0;

void func_004D7790(void) {
    int sp1C;
    int sp18;

    ScalarCollection_Init(&D_005838B8);
    __register_global_object(&D_005838B8, &func_0043BAC0, &D_005838A8);
    ScalarCollection_Init(&D_005838D8);
    __register_global_object(&D_005838D8, &func_0043BAC0, &D_005838C8);
    func_0043B9E0(&D_00583900, &sp1C, &sp18);
    __register_global_object(&D_00583900, &func_0043BA60, &D_005838E8);
}
