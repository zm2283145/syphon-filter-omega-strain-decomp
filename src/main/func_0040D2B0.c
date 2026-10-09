/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_0040D2B0(char* self) {
    return self + 4;
}

void func_0040D2C0(void) {
}

void* func_0040D2D0(void* self) {
    return self;
}

Map* func_0040D2E0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
