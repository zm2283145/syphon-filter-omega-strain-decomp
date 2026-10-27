/*
 * SFOGame/Source/GuiMissionSetup: 1 file, 002A1A50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002A1A50 */
#pragma push /* merge_units */
#include "types.h"

int GetNext(int a0, int a1, int a2, int a3) {
    int at, v0;
    int cond;

    cond = a3 == 0;
    if (cond) goto L002A1A60;
    a0 = a0 + 1;
    goto L002A1A68;
L002A1A60:;
    a0 = a0 + -1;
L002A1A68:;
    at = a0 < a1;
    cond = at == 0;
    if (cond) goto L002A1A78;
    a0 = a2;
L002A1A78:;
    at = a2 < a0;
    cond = at == 0;
    if (cond) goto L002A1A88;
    a0 = a1;
L002A1A88:;
    v0 = a0;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_002A1A50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002A1A50 */
