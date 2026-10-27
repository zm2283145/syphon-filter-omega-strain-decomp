#include "types.h"
extern char D_00493890;
extern char D_00493988;
extern char *D_0055A840;
extern int D_0055A848;
int cScriptBase_registerGlobalVar(char *, int, char *);
void StaticInit_gobjController(void) {
    D_0055A840 = "Gobj Controller";
    D_0055A848 = cScriptBase_registerGlobalVar("NpcDmgAimThresh", (int)&D_00493988, &D_00493890);
}
