#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Alloc(...);                        
int Font_ctor(...);                             
int ListReceiver_Ctor(...);                                  
int cConsole_ctor(...);                     
int cDME_ctor(...);                            
extern char D_0049C390;
extern char D_004D97B0;
extern unsigned char g_ProfileLockEnabled;
extern char D_0055A700;
extern int g_FrameCounter;
}
extern "C" char * App_Ctor(char * arg0) {
    int var_s2;
    int var_s1;
    int var_s0;

    ListReceiver_Ctor();
    F_(arg0, 0x0, int) = (int)(&D_004D97B0);
    cConsole_ctor(arg0 + 0x2C, "1.0", &D_0055A700);
    cDME_ctor(arg0 + 0x279);
    F_(arg0, 0x268, int) = 0;
    F_(arg0, 0x264, int) = 0;
    var_s2 = 0;
    g_FrameCounter = 0;
    var_s0 = 0;
    F_(arg0, 0x270, int) = 0;
    F_(arg0, 0x274, int) = 0;
    F_(arg0, 0x27C, int) = 0;
    F_(arg0, 0x278, signed char) = 0;
    do {
        {
            AllocGuard g;
        var_s1 = Mem_Alloc(0, 0x8A80, &D_0049C390, 0x97);
        }
        if (var_s1 != 0) {
            var_s1 = Font_ctor(var_s1);
        }
        F_((arg0 + var_s0), 0x280, int) = var_s1;
        var_s2 += 1;
        var_s0 += 4;
    } while (var_s2 < 3);
    return arg0;
}
