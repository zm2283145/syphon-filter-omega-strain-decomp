#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(char *, char *, char *);          
int func_00472380(char *, char *, char *);                     
extern char D_00588008;
extern char D_00588020;
extern char func_004723A0;

void func_004D8C10(void) {
    int sp1C;
    int sp18;

    func_00472380(&D_00588020, &sp1C, &sp18);
    __register_global_object(&D_00588020, &func_004723A0, &D_00588008);
}
