#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002824D0(char *, char *, char *);                   
extern char *D_00504068;
extern char D_00504070;
extern int D_00504078;
extern char func_0027C000;

void func_004D2730(void) {
    D_00504068 = "cNetGrenadeMsg";
    D_00504078 = func_002824D0(&func_0027C000, &D_00504070, "cNetGrenadeMsg");
}
