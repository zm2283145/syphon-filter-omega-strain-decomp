/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_0013A320(Map* m, int root);

/* Map clear: destroy all nodes and reset to empty. */
void Map_Clear_13A420(Map* m) {
    int root;

    root = m->head;
    if (root != 0) {
        func_0013A320(m, root);
        m->count = 0;
        m->head = 0;
        m->hp = &m->head;
    }
}

/* Map constructor with a comparator byte. */
Map* Map_Ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
