#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_004EA0B0;
extern signed char D_004EA0C8;

void func_004D2680(void) {
    if (D_004EA0C8 == 0) {
        D_004EA0B0 = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
