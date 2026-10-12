#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterType(char *, char *, int, int);            
int func_003D84F0(int, char *, char *, char *, int, char *);              
extern char D_00493888;
extern char *D_00583968;
extern int D_00583970;
extern int D_00583978;
extern int D_00583980;
extern char ScriptType_cWeaponVisChangeMsg_Init;
extern char Script_cWeaponVisChangeMsg_Visibility;

void func_004D7970(void) {
    D_00583968 = "Weapon Vis Change";
    D_00583970 = Script_RegisterType("cWeaponVisChangeMsg", &ScriptType_cWeaponVisChangeMsg_Init, 1, 0);
    D_00583978 = D_00583970;
    D_00583980 = func_003D84F0(D_00583970, &Script_cWeaponVisChangeMsg_Visibility, &D_00493888, "Visibility", 1, &D_00583970);
}
