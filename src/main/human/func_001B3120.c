/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void func_001BB080(int*, int, int);
extern int func_001BE870(void*, int*);

/* Erase by key: pass a local copy of the key to the tree erase routine. */
int ReceiverMap_Erase(void* map, int* key) {
    int k[1];

    k[0] = *key;
    return func_001BE870(map, k);
}

int func_001B3150(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* Tree lookup wrapper returning the found iterator through out. */
void func_001B3170(int* out) {
    int it[1];
    int a1, a2;

    func_001BB080(it, a1, a2);
    *out = it[0];
}

void func_001B31A0(Iter* out, Tree* t) {
    out->p = &t->header;
}
