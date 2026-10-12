#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002824D0(char *, char *, char *);                   
extern char *D_005061B0;
extern char D_005061B8;
extern int D_005061C0;
extern char func_00281620;

void func_004D27C0(void) {
    D_005061B0 = "cNetBackpackMsg";
    D_005061C0 = func_002824D0(&func_00281620, &D_005061B8, "cNetBackpackMsg");
}
