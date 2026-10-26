#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
unsigned int D_0048B250[4] = { 0x0, 0x0, 0x0, 0x0 };
extern char D_004FBB88;

int scePad2Init(void) {
    char *var_a0;

    (*(int*)D_0048B250) = 1;
    var_a0 = &D_004FBB88;
    do {
        F_(var_a0, 0x0, int) = 0;
        F_(var_a0, 0x4, int) = 0;
        F_(var_a0, 0x8, int) = 0;
        F_(var_a0, 0xC, int) = 0;
        var_a0 += 0x334;
    } while ((int) var_a0 < (int) (&D_004FBB88 + 0x3340));
    return 1;
}
