/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char* func_001F2E20(Iter16*);

char* func_001F2E10(Iter16* it) {
    return func_001F2E20(it);
}

/* Address 8 bytes past the pointed-to node. */
char* func_001F2E20(Iter16* it) {
    return it->p + 8;
}
