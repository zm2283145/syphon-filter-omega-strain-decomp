#include "types.h"
extern char D_00493890;
extern char D_00493988;
extern char *D_0055A840;
extern int D_0055A848;
int Script_RegisterVariable(char *, int, char *);
void func_004D6960(void) {
    D_0055A840 = "Gobj Controller";
    D_0055A848 = Script_RegisterVariable("NpcDmgAimThresh", (int)&D_00493988, &D_00493890);
}
