/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int cNIEventBase_NumActiveInTree(void* self, int flag);

/* True when index is below the count returned by cNIEventBase_NumActiveInTree(self, 1). */
int cNIEventBase_AreVUMsActive(void* self, int index) {
    int count = cNIEventBase_NumActiveInTree(self, 1);
    return index < count;
}
