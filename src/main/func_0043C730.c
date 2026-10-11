#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Hog_Register();                   
int func_001692D0();                          
int func_002071F0();                             
int func_0036E220();                            
int func_0036E4B0();                    
int func_0036E5D0();                               
int func_00380A40();                        
extern int D_00539248;

#pragma push
#pragma opt_common_subs off
int func_0043C730(char * arg0) {
    struct { int f20[40]; int fC0[40]; } sl;

    if (func_002071F0(arg0 + 0x50) == 0) {
        return 0;
    }
    if (F_(arg0, 0x4C, int) != 0) {
        func_0036E5D0(sl.fC0);
        Hog_Register(sl.fC0, func_001692D0(arg0 + 0x50), F_(arg0, 0x4C, int), 0);
        F_(arg0, 0x48, int) = func_00380A40(D_00539248, sl.fC0);
        func_0036E220(sl.fC0, -1);
    } else {
        func_0036E4B0(sl.f20, func_001692D0(arg0 + 0x50), 0, 0);
        F_(arg0, 0x48, int) = func_00380A40(D_00539248, sl.f20);
        func_0036E220(sl.f20, -1);
    }
    return ~F_(arg0, 0x48, int) != 0;
}
#pragma pop
