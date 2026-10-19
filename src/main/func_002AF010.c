#include "types.h"

int D_004ABE00 = 0x4E697547;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004ABE00) returned 0. */
int GuiNetAgencyCell_IsType(void) {
    return strcmp(&D_004ABE00) == 0;
}
