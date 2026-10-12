#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *D_0055D4D8;
extern char *D_0055D4E0;
extern signed char D_0055D4E8;
extern signed char D_0055D4F0;

void func_004D6D20(void) {
    if (D_0055D4E8 == 0) {
        D_0055D4D8 = "Move Message";
        D_0055D4E8 = 1;
    }
    if (D_0055D4F0 == 0) {
        D_0055D4E0 = "Teleport Message";
        D_0055D4F0 = 1;
    }
}
