#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(int, int, char *, int);                         
int RemoveIntcHandler(int, int);                            
int func_00381080(char * );                            
int func_00383150(char * , int);                         
int operator_delete(char * );                          
extern char D_004BC2B8;
extern unsigned char D_00533880;
}
extern "C" char * func_00383020(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        Alloc_Lock(5);
        RemoveIntcHandler(5, F_(arg0, 0x490, int));
        func_00381080(arg0);
        temp_s2 = F_(arg0, 0x8, int);
        {
            AllocGuard g;
        Mem_Free(0, temp_s2, &D_004BC2B8, 0x6E);
        }
        temp_a0 = arg0 + 0x434;
        if (temp_a0 != NULL) {
            func_00383150(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x428;
        if (temp_a0_2 != NULL) {
            func_00383150(temp_a0_2, 0);
        }
        temp_a0_3 = arg0 + 0x41C;
        if (temp_a0_3 != NULL) {
            func_00383150(temp_a0_3, 0);
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
