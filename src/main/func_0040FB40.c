/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern void func_0040F710(Tree* t, int root);

/* Address of the tree header (end()). */
int* func_0040FB40(Tree* t) {
    return &t->header;
}

void* func_0040FB50(void* self) {
    return self;
}

/* Erases every node of the tree and resets it to empty. */
void World_ClearPending(Tree* t) {
    if (t->header != 0) {
        func_0040F710(t, t->header);
        t->unk0 = 0;
        t->header = 0;
        t->leftmost = &t->header;
    }
}

Map* func_0040FBA0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
