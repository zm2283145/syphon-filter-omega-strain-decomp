/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern Rel* func_0018A8F0(Rel*);

/* Clear the three words and set the byte at +0x0C. */
Rel* func_0018A8C0(Rel* r) {
    func_0018A8F0(r);
    *((char*)r + 12) = 1;
    return r;
}
