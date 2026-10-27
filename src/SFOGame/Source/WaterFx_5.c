/*
 * SFOGame/Source/WaterFx: 1 file, 002B2F80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B2F80 */
#pragma push /* merge_units */
#include "types.h"

#define WATERFX_SLOTS 20

extern void opDelete_tBodyP_int_bool_charP_etc(int item, int a, int b, const char* file, int line);
extern char D_004ABFE0[]; /* source file name */

/* Releases every active water effect slot (+0x400, 20 slots) and decrements the count at +0x450. */
void cWaterFx_Purge(char* self) {
    char* slot = self;
    int i;
    for (i = 0; i < WATERFX_SLOTS; i++, slot += 4) {
        if (*(int*)(slot + 0x400) && i >= 0 && i < WATERFX_SLOTS) {
            opDelete_tBodyP_int_bool_charP_etc(*(int*)(slot + 0x400), 0, 1, D_004ABFE0, 0x1B6);
            *(int*)(slot + 0x400) = 0;
            (*(int*)(self + 0x450))--;
        }
    }
}
static inline void merge_flush_func_002B2F80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2F80 */
