#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Free(int, int, char *, int);                         
int __destroy_array(int, char *, int, int);                  
int func_001EF8D0(int, int);                            
int func_001EFA40(int, int);                            
extern char D_004A04A0;
extern int D_004F5358;
extern int D_004F5360;
extern int D_004F5368;
extern unsigned char D_00533880;
extern char HumanColPreset_Dtor;
}
extern "C" void HumanCol_Shutdown(void) {
    int temp_s0;
    int temp_s0_2;
    int temp_s0_3;

    temp_s0 = D_004F5358;
    if (temp_s0 != 0) {
        {
            AllocGuard g;
        if ((temp_s0 != 0) && (temp_s0 != 0)) {
            __destroy_array(temp_s0 + 0x10, &HumanColPreset_Dtor, 0xF0, 9);
        }
        Mem_Free(0, temp_s0, &D_004A04A0, 0x3F6);
        }
        D_004F5358 = 0;
    }
    temp_s0_2 = D_004F5360;
    if (temp_s0_2 != 0) {
        {
            AllocGuard g;
        if ((temp_s0_2 != 0) && (temp_s0_2 != 0) && (temp_s0_2 != 0)) {
            func_001EFA40(temp_s0_2, 0);
        }
        Mem_Free(0, temp_s0_2, &D_004A04A0, 0x3FE);
        }
        D_004F5360 = 0;
    }
    temp_s0_3 = D_004F5368;
    if (temp_s0_3 != 0) {
        {
            AllocGuard g;
        if ((temp_s0_3 != 0) && (temp_s0_3 != 0) && (temp_s0_3 != 0) && (temp_s0_3 != 0)) {
            func_001EF8D0(temp_s0_3, 0);
        }
        Mem_Free(0, temp_s0_3, &D_004A04A0, 0x406);
        }
        D_004F5368 = 0;
    }
}
