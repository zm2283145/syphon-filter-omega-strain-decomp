#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_CtorCStr_13B480();                      
typedef struct { char c; } Tag_08B0;
int String_Replace(void*, int, int, int, int, Tag_08B0);                  
int String_Dtor();                            
int func_0013D680();                          

void func_003D08B0(char * arg0, int arg1) {
    int sp20[3];

    if (arg1 != 0) {
        String_CtorCStr_13B480(sp20);
        func_0013D680(arg0 + 0x14, sp20);
        String_Dtor(sp20, 0);
        F_(arg0, 0x44, int) = 0;
        F_(arg0, 0x40, float) = (float) -F_(arg0, 0x8, int);
        F_(arg0, 0x4C, int) = 0;
        F_(arg0, 0x59, signed char) = 0;
        F_(arg0, 0x5A, signed char) = 0;
        return;
    }
    { Tag_08B0 tag; String_Replace(arg0 + 0x14, 0, -1, 0, 0, tag); }
}
