/*
 * SFOGame/Source/targetManager: 1 file, 0022D380
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022D380 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x98]; int a[30]; } S22D380;
int cTargetManager_FindGobj(S22D380* s, int v) {
    int i;
    for (i = 0; i < 30; i++) {
        if (s->a[i] == v) return i;
    }
    return -1;
}
static inline void merge_flush_func_0022D380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022D380 */
