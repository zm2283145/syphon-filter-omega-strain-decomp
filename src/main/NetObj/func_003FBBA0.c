#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetGame_InitLocalSlot(int *, int);                        
extern int D_00494178;
extern int D_0055C7B0;
extern int D_005721A8;
extern unsigned char D_005721C8;

int func_003FBBA0(void) {
    int var_a0;

    D_0055C7B0 += 1;
    LOCALID_(var_a0)
    return D_0055C7B0 + (var_a0 * 0x3E8);
}
