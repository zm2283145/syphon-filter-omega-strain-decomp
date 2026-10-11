#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (D_005721C8) { if (D_00494178 == -1) func_002EBAF8(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002EBAF8(int *, int);                        
int func_004343E0(int, int);                        
extern int D_00494178;
extern int D_0055C988;
extern int D_005721A8;
extern unsigned char D_005721C8;

int func_003FBC40(int arg0) {
    int var_s0;

    LOCALID_(var_s0)
    return var_s0 == func_004343E0(D_0055C988, arg0);
}
