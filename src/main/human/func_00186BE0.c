/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* Address of the 8-byte entry i. */
char* History_At(PtrVec* v, int i) {
    return (char*)v->data + (i << 3);
}
