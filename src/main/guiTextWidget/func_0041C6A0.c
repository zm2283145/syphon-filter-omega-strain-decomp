#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int Mem_Free(...);                         
int func_00138B70(...);                         
int func_0041F370(...);                         
int operator_delete(...);                          
extern char D_004BF2D0;
extern char D_004E0AC0;
extern unsigned char D_00533880;
}
extern "C" char * func_0041C6A0(char * arg0, long long arg1) {
    int temp_s2;
    char * temp_a0;
    char * temp_a0_2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&D_004E0AC0);
        temp_s2 = F_(arg0, 0x78, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            if (temp_s2 != 0) {
                temp_a0 = (char *)(temp_s2 + 0x14);
                if (temp_a0 != NULL) {
                    func_00138B70(temp_a0, 0);
                }
            }
            Mem_Free(0, temp_s2, &D_004BF2D0, 0x23);
            }
        }
        temp_a0_2 = arg0 + 0x48;
        if (temp_a0_2 != NULL) {
            func_00138B70(temp_a0_2, 0);
        }
        func_0041F370(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
