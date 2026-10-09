/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_004209B0(char* self) {
    return self + 4;
}

List* func_004209C0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
