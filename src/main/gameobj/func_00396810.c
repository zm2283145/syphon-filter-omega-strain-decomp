#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int cMemMan_Deallocate(...);                           
int cSkaAnimCheckpoints_dtor(...);                            
int cSkaAnimEndedMessage_dtor(...);                            
int func_00396910(...);                            
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void opDelete_cSkaSystemRequestP_int_bool_charP_etc(int arg0, int arg1, int arg2, int arg3, char * arg4) {
    {
        AllocGuard g;
    if ((arg2 != 0) && (arg0 != 0)) {
        func_00396910(arg0 + 0xE8, -1);
        cSkaAnimCheckpoints_dtor(arg0 + 0x94, -1);
        cSkaAnimEndedMessage_dtor(arg0 + 0x5C, -1);
        cSkaAnimEndedMessage_dtor(arg0 + 0x24, -1);
    }
    cMemMan_Deallocate(arg1, arg0, arg3, arg4);
    }
}
