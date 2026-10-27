/*
 * Libs/SFOLib/Source/hoglist: 1 file, 003F9A30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9A30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int cMemMan_Deallocate(...);                     
int cHogFile_dtor(...);                         
extern char D_0049AE60;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" void std_list_deleter_cHogFile_erase_listdeleter(void ***arg0, int *arg1, void ***arg2) {
    void **temp_s0;

    temp_s0 = *arg2;
    *arg2 = (void **)(F_(temp_s0, 0x4, int));
    F_(F_(temp_s0, 0x0, int), 0x4, int) = (int)(F_(temp_s0, 0x4, int));
    *(int *)F_(temp_s0, 0x4, int) = F_(temp_s0, 0x0, int);
    cHogFile_dtor((char *)temp_s0 + 8, -1);
    if (temp_s0 != NULL) {
        {
            AllocGuard g;
        cMemMan_Deallocate(0, temp_s0, &D_0049AE60, 0x64);
        }
    }
    *arg1 -= 1;
    *arg0 = *arg2;
}
static inline void merge_flush_func_003F9A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9A30 */
