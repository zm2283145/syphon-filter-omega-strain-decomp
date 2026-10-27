#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_addClass(char *, char *, int, int);            
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(int, char *, char *, char *, int, char *);              
extern char D_00493888;
extern char *D_00583968;
extern int D_00583970;
extern int D_00583978;
extern int D_00583980;
extern char cWeaponVisChangeMsg_SOBJ_init;
extern char Script_cWeaponVisChangeMsg_Visibility;

void StaticInit_WeaponVisChangeMsg(void) {
    D_00583968 = "Weapon Vis Change";
    D_00583970 = cScriptBase_addClass("cWeaponVisChangeMsg", &cWeaponVisChangeMsg_SOBJ_init, 1, 0);
    D_00583978 = D_00583970;
    D_00583980 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00583970, &Script_cWeaponVisChangeMsg_Visibility, &D_00493888, "Visibility", 1, &D_00583970);
}
