/*
 * Matched functions (byte-identical with the retail executable).
 * Texture entry release.
 */

#include "types.h"
#include "texman_types.h"

void cTexture_DecRefCount(TexEntry* e) {
    e->refCount = e->refCount + -1;
}
