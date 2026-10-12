#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterNative_2(char *, char *, char *, int, char *);                
int func_003D8F60(char *, char *, int);                     
extern char D_0048A070;
extern char D_00493880;
extern int D_004EE538;
extern int D_004EE540;
extern char Script_SetInterfaceFont;

void func_004C5980(void) {
    D_004EE538 = func_003D8F60("eFontType", &D_0048A070, 2);
    D_004EE540 = Script_RegisterNative_2(&Script_SetInterfaceFont, &D_00493880, "SetInterfaceFont", 1, &D_004EE538);
}
