/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern Rel* func_0017F9B0(Rel*);

/* Clears the three words and sets byte +0xC. */
Rel* func_0017F980(Rel* r) {
    func_0017F9B0(r);
    *((char*)r + 12) = 1;
    return r;
}
