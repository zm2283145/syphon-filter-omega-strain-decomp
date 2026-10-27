#include "types.h"

int D_004C0420 = 0x57697547;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004C0420) returned 0. */
int GuiWeaponDisplay_IsClass(void) {
    return strcmp(&D_004C0420) == 0;
}
