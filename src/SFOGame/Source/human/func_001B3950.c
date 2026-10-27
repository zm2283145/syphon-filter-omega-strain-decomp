/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void cSKM_GOBJ_Init(void*);

void cHuman_Init(void* self) {
    cSKM_GOBJ_Init(self);
}
