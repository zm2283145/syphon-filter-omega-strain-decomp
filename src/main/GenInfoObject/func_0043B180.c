/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int func_00439670(void);
extern int func_0043B410(Map* m, int node);     /* frees a subtree */

void func_0043B180(Iter* out, PtrVec* v) {
    out->p = v->data;
}

int func_0043B190(int a0) {
    func_00439670();
    return a0;
}

/* clear(): frees all nodes and resets the map to empty. */
void Map_Clear(Map* m) {
    int root = m->head;

    if (root != 0) {
        func_0043B410(m, root);
        m->count = 0;
        m->head = 0;
        m->hp = &m->head;
    }
}
