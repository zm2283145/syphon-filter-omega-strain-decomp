/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "types.h"

void* func_00437440(char* self) {
    return self + 4;
}

void func_00437450(void) {
}

void* func_00437460(void* self) {
    return self;
}

Map* func_00437470(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
