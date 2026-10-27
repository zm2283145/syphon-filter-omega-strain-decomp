/*
 * SFOGame/Source/WaterFx: 1 file, 002B1CB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B1CB0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x40]; char splash[0x30]; char ripples[0x10]; } WaterFx;
typedef struct { char pad[0x400]; WaterFx* fx[20]; } WaterFxMgr;
extern void cSplash_Render(void*);
extern void cWake_Render(void*);
void cWaterFx_Render(WaterFxMgr* m)
{
    int i;
    WaterFxMgr* q = m;
    for (i = 0; i < 20; i++, q = (WaterFxMgr*)((char*)q + 4)) {
        WaterFx* p = q->fx[0];
        if (p) {
            cSplash_Render(p->splash);
            cWake_Render(p->ripples);
        }
    }
}
static inline void merge_flush_func_002B1CB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B1CB0 */
