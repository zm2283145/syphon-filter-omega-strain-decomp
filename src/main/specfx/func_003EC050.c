#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...);                      
int func_003EC130(...);                            
int func_003EC8E0(...);                         
extern int D_004BE020;
extern int D_004E0760;
extern unsigned char D_00533880;
}
extern "C" int func_003EC050(int arg0, long long arg1) {
    if (arg0 != NULL) {
        F_(arg0, 0x14, int) = (int)(&D_004E0760);
        func_003EC130(arg0, arg0);
        func_003EC8E0(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            {
                AllocGuard g;
            Mem_Free(0, arg0, &D_004BE020, 0xE9);
            }
        }
    }
    return arg0;
}
