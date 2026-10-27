/*
 * SFOGame/Source/fire: 2 files, 00262460-00262470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00262460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Empty / constant virtual methods.
 */

#include "types.h"

int cFireObj_HandleMessage(void) {
    return 0;
}
static inline void merge_flush_func_00262460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00262460 */

/* merge_units: begin func_00262470 */
#pragma push /* merge_units */
const float D_0048B0E0[2] = { 1.4013e-42f, 0.0f };
typedef struct { char pad[0x60]; int v; } T262470;
void cFireObj_SetIntensity(T262470* p, float f) {
    p->v = (int)((float)(*(int*)D_0048B0E0) * f / 100.0f);
}
static inline void merge_flush_func_00262470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00262470 */
