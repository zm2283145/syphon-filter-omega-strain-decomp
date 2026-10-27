/*
 * SFOGame/Source/Checkpoint: 1 file, 0022EA20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022EA20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int nGlobalization_GetString_charP(...);                            
int cMemMan_Allocate(...);                      
int cMemMan_Deallocate(...);                         
int Libc_Strcpy(...);                            
int strlen(...);                                    
extern char D_004A6698;
extern unsigned char g_ProfileLockEnabled;
}
#pragma opt_common_subs off
extern "C" void cCheckpoint_SetString(char * arg0, int arg1) {
    int temp_s2;
    int temp_s2_2;
    int temp_s2_3;
    int temp_v0;

    temp_s2 = F_(arg0, 0x70, int);
    if (temp_s2 != 0) {
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s2, &D_004A6698, 0x3F);
        }
    }
    if (arg1 != 0) {
        F_(arg0, 0x70, int) = arg1;
    } else {
        temp_v0 = nGlobalization_GetString_charP("Checkpoint");
        temp_s2_2 = strlen(temp_v0) + 1;
        {
            AllocGuard g;
        temp_s2_3 = cMemMan_Allocate(0, temp_s2_2, &D_004A6698, 0x47);
        }
        F_(arg0, 0x70, int) = temp_s2_3;
        Libc_Strcpy(F_(arg0, 0x70, int), temp_v0);
    }
    F_(arg0, 0x6C, int) = 0x40A00000;
}
static inline void merge_flush_func_0022EA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022EA20 */
