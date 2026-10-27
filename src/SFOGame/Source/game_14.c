/*
 * SFOGame/Source/game: 1 file, 001307F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001307F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Allocate(...);                        
int cMemMan_Deallocate(...);                         
int cHud_dtor(...);                            
int cHud_ctor(...);           
extern char D_0049A890;
extern unsigned char g_ProfileLockEnabled;
}
#pragma opt_common_subs off
extern "C" int cGameSystem_LoadHud(char * arg0) {
    int temp_s1;
    int var_s1;

    temp_s1 = F_(arg0, 0xDC, int);
    if (temp_s1 != 0) {
        {
            AllocGuard g;
        cHud_dtor(temp_s1, -1);
        cMemMan_Deallocate(0, temp_s1, &D_0049A890, 0x97D);
        }
    }
    {
        AllocGuard g;
    var_s1 = cMemMan_Allocate(0, 0x700, &D_0049A890, 0x97F);
    }
    if (var_s1 != 0) {
        var_s1 = cHud_ctor(var_s1, arg0 + 0x3C, "IARCADEN", "IAMAP");
    }
    F_(arg0, 0xDC, int) = var_s1;
    return 1;
}
static inline void merge_flush_func_001307F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001307F0 */
