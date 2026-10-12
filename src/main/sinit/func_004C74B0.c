#include "types.h"
int Script_LoadAnimation();
int func_003D8740();
extern char D_00493880;
extern char D_00493898;
extern int D_004EF090;
void func_004C74B0(void) {
    D_004EF090 = func_003D8740(Script_LoadAnimation, &D_00493880, "LoadAnimation", 1, &D_00493898);
}
