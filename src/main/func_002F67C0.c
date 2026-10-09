/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* True when the record exists, both flag bytes are set and the state is below 4. */
int func_002F67C0(RtState* s) {
    int result = 0;

    if (s != 0 && s->unk00 != 0 && s->unk01 != 0) {
        result = s->state < 4;
    }
    return result;
}
