#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int Event_Construct();                             
int func_001437A0(int );                          
extern int D_004DCBF0;
extern int D_004DCD70;
extern int D_004FF2A0;

int cAIWeaponFiredMsg_ctor(int arg0, int arg1, int arg2, int arg3) {
    Event_Construct(arg0, &D_004FF2A0);
    F_(arg0, 0x0, int) = (int)(&D_004DCD70);
    F_(arg0, 0x24, int) = arg1;
    F_(arg0, 0x20, signed char) = 2;
    F_(arg0, 0x0, int) = (int)(&D_004DCBF0);
    F_(arg0, 0x2C, int) = arg3;
    if (arg2 != NULL) {
        F_(arg0, 0x30, signed char) = (signed char) ((func_001437A0(arg2) & 0xFF) == 1);
        F_(arg0, 0x28, int) = (int) F_(((char *)(F_(arg2, 0x84, unsigned char) * 0x10) + (int)(arg2)), 0x8, int);
    } else {
        F_(arg0, 0x28, int) = -1;
        F_(arg0, 0x30, signed char) = 0;
    }
    return arg0;
}
