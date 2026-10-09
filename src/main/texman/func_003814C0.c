/*
 * Matched functions (byte-identical with the retail executable).
 * Texture entry release.
 */

#include "types.h"
#include "texman_types.h"

void TexEntry_Release(TexEntry* e) {
    e->refCount = e->refCount + -1;
}
