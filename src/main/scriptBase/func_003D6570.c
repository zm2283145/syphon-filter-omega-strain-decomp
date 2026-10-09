/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptBase_types.h"

/* Number of 4-byte words needed for 'size' bytes. */
unsigned int func_003D6570(int a0, int size) {
    return (unsigned int)(size + 3) >> 2;
}
