/*
 * Matched functions (byte-identical with the retail executable).
 * Texture entry reference count accessor.
 */

#include "types.h"
#include "texman_types.h"

int func_00380360(TexEntry* e) {
    return e->refCount;
}
