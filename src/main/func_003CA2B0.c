/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_003CA2B0(char* self) {
    return self + 4;
}

Map* func_003CA2C0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

List* func_003CA2E0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
