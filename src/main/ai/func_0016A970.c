#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(...);                        
int func_0016A0A0(...);                                  
int func_0016A750(...);                               
extern unsigned char D_0048A100;
extern char D_0049C650;
extern int D_004EE620;
extern unsigned char D_004EE628;
extern unsigned char D_00533880;
extern unsigned char D_005721C8;
}
extern "C" void func_0016A970(void) {
    int temp_s0;

    if (D_005721C8 != 0) {
        if (D_004EE628 == 0) {
            func_0016A0A0();
        }
        if (D_0048A100 != 0) {
            D_0048A100 = 0;
            func_0016A750(D_004EE620);
        }
    } else {
        if (D_004EE620 == 0) {
            {
                AllocGuard g;
            temp_s0 = Mem_Alloc(0, 0x100, &D_0049C650, 0x71B);
            }
            asm { nop } /* scheduling barrier: keeps the store after the unlock, as in retail */
            D_004EE620 = temp_s0;
        }
        func_0016A750(D_004EE620);
    }
}


