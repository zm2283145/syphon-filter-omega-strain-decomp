#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetGame_InitLocalSlot(int *, int);                        
int func_004361C0(int, int);                            
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;

unsigned char func_004340C0(int arg0, int arg1) {
    int temp_v0;
    unsigned char var_s1;
    int var_s0;
    int var_v0;

    temp_v0 = func_004361C0(arg1, 0);
    var_s1 = 0;
    if (temp_v0 != 0) {
        var_s0 = 0;
        do {
            LOCALID_(var_v0)
            if ((var_s0 != var_v0) && (F_((temp_v0 + var_s0), 0x6, unsigned char) != 0)) {
                var_s1 = 1;
            }
            var_s0 += 1;
        } while (var_s0 < 4);
    }
    return var_s1;
}
