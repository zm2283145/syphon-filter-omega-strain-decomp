#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(char *, char *, char *);          
int func_0040D2E0(char *, char *, char *);                     
extern int D_00571770;
extern int D_00571774;
extern char D_00571C00;
extern char D_00571C10;
extern char func_0040D360;

void func_004D6FC0(void) {
    int sp1C;
    int sp18;

    D_00571770 = 0;
    D_00571774 = -2;
    func_0040D2E0(&D_00571C10, &sp1C, &sp18);
    __register_global_object(&D_00571C10, &func_0040D360, &D_00571C00);
}
