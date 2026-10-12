#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002824D0(char *, char *, char *);                   
extern char *D_00504050;
extern char D_00504058;
extern int D_00504060;
extern char func_0027BB00;

void func_004D26F0(void) {
    D_00504050 = "cNetTaserMsg";
    D_00504060 = func_002824D0(&func_0027BB00, &D_00504058, "cNetTaserMsg");
}
