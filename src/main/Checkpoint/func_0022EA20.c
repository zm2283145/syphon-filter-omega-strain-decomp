#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Loc_LookupText(...);                            
int Mem_Alloc(...);                      
int Mem_Free(...);                         
int String_Copy(...);                            
int strlen(...);                                    
extern char D_004A6698;
extern unsigned char D_00533880;
}
#pragma opt_common_subs off
extern "C" void Checkpoint_SetLabel(char * arg0, int arg1) {
    int temp_s2;
    int temp_s2_2;
    int temp_s2_3;
    int temp_v0;

    temp_s2 = F_(arg0, 0x70, int);
    if (temp_s2 != 0) {
        {
            AllocGuard g;
        Mem_Free(0, temp_s2, &D_004A6698, 0x3F);
        }
    }
    if (arg1 != 0) {
        F_(arg0, 0x70, int) = arg1;
    } else {
        temp_v0 = Loc_LookupText("Checkpoint");
        temp_s2_2 = strlen(temp_v0) + 1;
        {
            AllocGuard g;
        temp_s2_3 = Mem_Alloc(0, temp_s2_2, &D_004A6698, 0x47);
        }
        F_(arg0, 0x70, int) = temp_s2_3;
        String_Copy(F_(arg0, 0x70, int), temp_v0);
    }
    F_(arg0, 0x6C, int) = 0x40A00000;
}
