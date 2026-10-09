/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator helpers.
 */

#include "types.h"
#include "texman_types.h"

TexListIter* func_00380250(TexListIter* it, TexListNode* node) {
    it->node = node;
    return it;
}

void* func_00380260(char* self) {
    return self + 4;
}

void* func_00380270(void* self) {
    return self;
}
