/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

/* Construct an empty map with comparator byte *cmp. */
Map* func_001C4650(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
