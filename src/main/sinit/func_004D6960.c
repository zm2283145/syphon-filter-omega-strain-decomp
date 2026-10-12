#include "types.h"
extern char D_00493890;
extern char D_00493988;
extern char *D_0055A840;
extern int D_0055A848;
int func_003D8A30(char *, int, char *);
void func_004D6960(void) {
    D_0055A840 = "Gobj Controller";
    D_0055A848 = func_003D8A30("NpcDmgAimThresh", (int)&D_00493988, &D_00493890);
}
