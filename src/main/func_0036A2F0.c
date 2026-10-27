/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Return the resource's byte-sized row-height metric through the integer ABI. */
unsigned int cFont_GetCharH(unsigned char* self) {
    return self[153];
}
