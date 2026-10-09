/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern FxLightSet* D_004FFC30;

/* args[0] = light index (0..4), args[1] = distance. */
int Script_setFxLightDist(ScriptArg* args) {
    volatile ScriptArg d; /* argument passes through the stack */
    FxLightSet* set;
    unsigned int index;
    float dist;

    d.i = args[1].i;
    set = D_004FFC30;
    index = args[0].i;
    dist = d.f;
    if (index < 5) {
        set->lights[index].dist = dist;
    }
    return 0;
}
