#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003D8F60(char *, char *, int);                     
extern char D_004975A0;
extern char D_00497660;
extern int D_00583918;
extern int D_00583920;

void func_004D7830(void) {
    D_00583918 = func_003D8F60("eWpnDamageType", &D_004975A0, 0x10);
    D_00583920 = func_003D8F60("eHitLocation", &D_00497660, 5);
}
