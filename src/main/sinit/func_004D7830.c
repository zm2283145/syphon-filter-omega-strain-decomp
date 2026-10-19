#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int ScriptEnum_Register(char *, char *, int);                     
extern char D_004975A0;
extern char D_00497660;
extern int D_00583918;
extern int D_00583920;

void StaticInit_RegisterWeaponDamageEnums(void) {
    D_00583918 = ScriptEnum_Register("eWpnDamageType", &D_004975A0, 0x10);
    D_00583920 = ScriptEnum_Register("eHitLocation", &D_00497660, 5);
}
