/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_0043B9B0(char* self) {
    return self + 4;
}

void func_0043B9C0(void) {
}

void* func_0043B9D0(void* self) {
    return self;
}

Map* func_0043B9E0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
