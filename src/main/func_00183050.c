/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* End of a counted pointer array {count, items[]}. */
void** cArray_FixedCapacity_cGOBJPtr_2_End(PtrStack* s) {
    return &s->items[s->count];
}
