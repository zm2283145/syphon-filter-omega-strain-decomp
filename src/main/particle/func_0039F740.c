#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int func_003813A0(...);                       
int operator_delete(...);                          
extern char D_004BC5D0;
extern char D_004DFAD8;
extern "C" void func_0039B7B0();
extern "C" void func_0039CB70();
extern "C" void func_0039EF10();
extern "C" void func_003A23F0();
extern "C" void func_003A6090();
extern void * const D_004DFB10[];
extern char D_004DFB50;
extern unsigned char D_00533880;
extern int D_00539248;
}
#pragma opt_common_subs off
extern "C" char * func_0039F740(char * arg0, long long arg1) {
    int temp_a1;
    int temp_s2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004DFB10));
        temp_a1 = F_(arg0, 0x170, int);
        if (temp_a1 >= 0) {
            func_003813A0(D_00539248, temp_a1, 1);
        }
        temp_s2 = F_(arg0, 0x124, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s2, &D_004BC5D0, 0x99B);
            }
            F_(arg0, 0x124, int) = 0;
        }
        if (arg0 != NULL) {
            F_(arg0, 0x0, int) = (int)(&D_004DFB50);
            if (arg0 != NULL) {
                F_(arg0, 0x0, int) = (int)(&D_004DFAD8);
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DFB10[8] = { (void*)0x0, (void*)0x0, (void*)func_0039F740, (void*)func_0039B7B0, (void*)func_0039CB70, (void*)func_003A6090, (void*)func_0039EF10, (void*)func_003A23F0 };
