#include "types.h"
int Script_LoadAnimation();
int Script_RegisterNative_2();
extern char D_00493880;
extern char D_00493898;
extern int D_004EF090;
void StaticInit_RegisterLoadAnimation(void) {
    D_004EF090 = Script_RegisterNative_2(Script_LoadAnimation, &D_00493880, "LoadAnimation", 1, &D_00493898);
}
