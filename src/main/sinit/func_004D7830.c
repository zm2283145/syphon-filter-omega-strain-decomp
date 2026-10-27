#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_registerEnum(char *, char *, int);                     
extern char D_004975A0;
extern char D_00497660;
extern int D_00583918;
extern int D_00583920;

void StaticInit_wpnEnums(void) {
    D_00583918 = cScriptBase_registerEnum("eWpnDamageType", &D_004975A0, 0x10);
    D_00583920 = cScriptBase_registerEnum("eHitLocation", &D_00497660, 5);
}
