/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern Rel* ItemList_Reset(Rel*);

/* Clear the three words and set the byte at +0x0C. */
Rel* ItemList_Init(Rel* r) {
    ItemList_Reset(r);
    *((char*)r + 12) = 1;
    return r;
}
