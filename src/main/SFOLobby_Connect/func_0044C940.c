#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_Copy();                            
int func_00451B00();                 
int func_00468F78();                             
int memset();                                
extern char D_004C0E80;

#pragma opt_common_subs off
int func_0044C940(char * arg0, int arg1) {
    struct { int f30[5]; int f44[3]; } sl;

    memset(sl.f30, 0, 0x18);
    String_Copy(sl.f30, arg0 + 0x2418);
    sl.f44[0] = arg1;
    F_(arg0, 0x24C, int) = func_00468F78(sl.f30);
    if (F_(arg0, 0x24C, int) != 0) {
        func_00451B00(arg0, 0xD, &D_004C0E80, 0x2D1);
        return 0;
    }
    return 1;
}
