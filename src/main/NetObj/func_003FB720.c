/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NetObj_types.h"

extern int func_003FB750(int index);

/* Takes the 7-bit field in bits 24..30 of word +0x0C, converts it to a zero-based
 * index (clamped at 0) and forwards it to func_003FB750. */
int func_003FB720(NetObjFlags* obj) {
    int index = ((obj->flags & 0x7f000000) >> 24) - 1;
    if (index < 0) {
        index = 0;
    }
    return func_003FB750(index);
}
