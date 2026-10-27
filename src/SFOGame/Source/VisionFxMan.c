/*
 * SFOGame/Source/VisionFxMan: 1 file, 0025E460
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025E460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern FxLightSet* g_VisionFxMan;

/* args[0] = light index (0..4), args[1] = distance. */
int Script_setFxLightDist(ScriptArg* args) {
    volatile ScriptArg d; /* argument passes through the stack */
    FxLightSet* set;
    unsigned int index;
    float dist;

    d.i = args[1].i;
    set = g_VisionFxMan;
    index = args[0].i;
    dist = d.f;
    if (index < 5) {
        set->lights[index].dist = dist;
    }
    return 0;
}
static inline void merge_flush_func_0025E460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025E460 */
