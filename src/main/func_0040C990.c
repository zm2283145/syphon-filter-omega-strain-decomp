/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Records the registry an object belongs to (called by Object_Register). */
void Object_SetRegistry(L4RegObj* obj, int registry) {
    obj->registry = registry;
}
