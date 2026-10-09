/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_003CB590(int a0, int a1) {
    return ((unsigned int)((a1 ^ *(int*)((char*)a0 + 12))) < (unsigned int)(1));
}

Map* func_003CB5A0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
