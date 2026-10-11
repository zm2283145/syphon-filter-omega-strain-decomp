#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int HumanCol_InstallPresets(...);                        
int *Mem_Alloc(...);                       
int __construct_array(...);            
int func_001361D0(...);                           
int func_001EB800(...);                   
int func_001EB870(...);                        
int func_001EB880(...);                             
extern char D_004A04A0;
extern int *D_004F5358;
extern int *D_004F5360;
extern int *D_004F5368;
extern unsigned char D_00533880;
extern char HumanColPreset_Ctor;
extern char HumanColPreset_Dtor;
}
extern "C" void HumanCol_Init(void) {
    int sp3C;
    int sp38;
    int *temp_s0;
    int *temp_s0_2;
    int *temp_s0_3;

    if (D_004F5358 == NULL) {
        {
            AllocGuard g;
        temp_s0 = Mem_Alloc(0, 0x880, &D_004A04A0, 0x3DC);
        }
        if (temp_s0 != NULL) {
            *temp_s0 = 0;
            __construct_array((char *)temp_s0 + 0x10, &HumanColPreset_Ctor, &HumanColPreset_Dtor, 0xF0, 9);
        }
        D_004F5358 = temp_s0;
        HumanCol_InstallPresets();
    }
    if (D_004F5360 == NULL) {
        {
            AllocGuard g;
        temp_s0_2 = Mem_Alloc(0, 0x10, &D_004A04A0, 0x3E4);
        }
        if (temp_s0_2 != NULL) {
            sp3C = 0x96;
            func_001EB880(temp_s0_2);
            func_001EB870(temp_s0_2, func_001361D0(&sp3C));
            F_(temp_s0_2, 0xC, signed char) = 1;
        }
        D_004F5360 = temp_s0_2;
    }
    if (D_004F5368 == NULL) {
        {
            AllocGuard g;
        temp_s0_3 = Mem_Alloc(0, 0x10, &D_004A04A0, 0x3EB);
        }
        if (temp_s0_3 != NULL) {
            sp38 = 0x96;
            func_001EB800(temp_s0_3, &sp38, 1);
        }
        D_004F5368 = temp_s0_3;
    }
}
