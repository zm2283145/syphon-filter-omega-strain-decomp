#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_CtorCStr_13B480();                      
int func_00138B70();                            
int func_00413FB0();               

#pragma opt_common_subs off
void func_00413880(char * arg0) {
    int sp20[4];
    char * temp_a0;

    if (F_(arg0, 0x1E4, int) != NULL) {
        String_CtorCStr_13B480(sp20);
        temp_a0 = (char *)(F_(arg0, 0x1E4, int));
        func_00413FB0(temp_a0, F_(temp_a0, 0x8, int) + (F_(temp_a0, 0x4, int) * 0xC), 1, sp20);
        func_00138B70(sp20, 0);
    }
}
