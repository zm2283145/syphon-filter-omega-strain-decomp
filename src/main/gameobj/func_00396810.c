#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...);                           
int func_00189F40(...);                            
int AnimEvent_dtor(...);                            
int func_00396910(...);                            
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void func_00396810(int arg0, int arg1, int arg2, int arg3, char * arg4) {
    {
        AllocGuard g;
    if ((arg2 != 0) && (arg0 != 0)) {
        func_00396910(arg0 + 0xE8, -1);
        func_00189F40(arg0 + 0x94, -1);
        AnimEvent_dtor(arg0 + 0x5C, -1);
        AnimEvent_dtor(arg0 + 0x24, -1);
    }
    Mem_Free(arg1, arg0, arg3, arg4);
    }
}
