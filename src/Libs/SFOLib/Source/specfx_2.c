/*
 * Libs/SFOLib/Source/specfx: 1 file, 003EC050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC050 */
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
int cSfxScheduler_ClearItemList(...);                            
int cSfxScheduler_dtor(...);                         
extern int D_004BE020;
extern "C" void cSfxScheduler_Render();
extern "C" void cSfxScheduler_NextFrame();
extern void * const D_004E0760[];
extern unsigned char g_ProfileLockEnabled;
}
extern "C" int cSfxBundle_dtor(int arg0, long long arg1) {
    if (arg0 != NULL) {
        F_(arg0, 0x14, int) = (int)(&(*(int*)D_004E0760));
        cSfxScheduler_ClearItemList(arg0, arg0);
        cSfxScheduler_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            {
                AllocGuard g;
            cMemMan_Deallocate(0, arg0, &D_004BE020, 0xE9);
            }
        }
    }
    return arg0;
}
void * const D_004E0760[8] = { (void*)0x0, (void*)0x0, (void*)cSfxBundle_dtor, (void*)cSfxScheduler_NextFrame, (void*)cSfxScheduler_Render, (void*)0x0, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_003EC050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003EC050 */
