#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern char *g_LosCheckService;
extern signed char D_004EA0C8;

void func_004D2680(void) {
    if (D_004EA0C8 == 0) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
