#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(char *, char *, char *, int, char *);                
int cScriptBase_registerEnum(char *, char *, int);                     
extern char D_0048A070;
extern char D_00493880;
extern int D_004EE538;
extern int D_004EE540;
extern char Script_SetInterfaceFont;

void StaticInit_machine(void) {
    D_004EE538 = cScriptBase_registerEnum("eFontType", &D_0048A070, 2);
    D_004EE540 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(&Script_SetInterfaceFont, &D_00493880, "SetInterfaceFont", 1, &D_004EE538);
}
