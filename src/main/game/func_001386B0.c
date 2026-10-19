#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
char * Mem_Alloc(int, int, char *, int);                      
int Vec4_Assign(...);                      
int cMessage_ctor(...);                    
extern char D_004D9180;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * func_001386B0(char * arg0) {
    char * temp_s0;

    {
        AllocGuard g;
    temp_s0 = (char *)(Mem_Alloc(0, 0x60, "los.hh", 0x181));
    }
    if (temp_s0 != NULL) {
        cMessage_ctor(temp_s0, arg0);
        F_(temp_s0, 0x0, int) = (int)(&D_004D9180);
        F_(temp_s0, 0x24, int) = F_(arg0, 0x24, int);
        F_(temp_s0, 0x28, int) = F_(arg0, 0x28, int);
        F_(temp_s0, 0x2C, int) = F_(arg0, 0x2C, int);
        Vec4_Assign(temp_s0 + 0x30, arg0 + 0x30);
        Vec4_Assign(temp_s0 + 0x40, arg0 + 0x40);
        F_(temp_s0, 0x50, int) = F_(arg0, 0x50, int);
        F_(temp_s0, 0x54, int) = F_(arg0, 0x54, int);
        F_(temp_s0, 0x58, int) = F_(arg0, 0x58, int);
        F_(temp_s0, 0x5C, signed char) = F_(arg0, 0x5C, signed char);
    }
    return temp_s0;
}
