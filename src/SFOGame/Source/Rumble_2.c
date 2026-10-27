/*
 * SFOGame/Source/Rumble: 1 file, 0026BD60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026BD60 */
#pragma push /* merge_units */
#include "types.h"

extern char D_004FEED0[];
extern char D_0055A340[];
extern char D_0055A500[];
extern int cJoyPad_SetVibration(int, int, int);

int nRumbleManager_StopAll(void) {
    int a0, a1, a2, v0, v1;
    int cond;

    a0 = 0;
    v1 = (int)D_004FEED0;
L0026BD78:;
    *(char*)((char*)v1 + 24) = 0;
    *(char*)((char*)v1 + 52) = 0;
    a0 = a0 + 1;
    *(char*)((char*)v1 + 80) = 0;
    v0 = a0 < 2;
    *(char*)((char*)v1 + 108) = 0;
    *(char*)((char*)v1 + 136) = 0;
    *(char*)((char*)v1 + 164) = 0;
    cond = v0 != 0;
    v1 = v1 + 168;
    if (cond) goto L0026BD78;
    a1 = 0;
    a0 = (int)D_0055A340;
    a2 = 0;
    v0 = cJoyPad_SetVibration(a0, a1, a2);
    a1 = 0;
    a0 = (int)D_0055A500;
    a2 = 0;
    v0 = cJoyPad_SetVibration(a0, a1, a2);
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_0026BD60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026BD60 */
