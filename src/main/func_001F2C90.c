/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int ListIter_NotEqual(ListIter*, ListIter*);
extern ListIter* func_001F2CF0(ListIter*);
extern ListIter* ListIter_Next(ListIter*);
extern void func_001F2D50(void);

int func_001F2C90(ListIter* a, ListIter* b) {
    return ListIter_NotEqual(a, b);
}

/* Iterator inequality. */
int ListIter_NotEqual(ListIter* a, ListIter* b) {
    return ((unsigned int)(0) < (unsigned int)(((int)a->node ^ (int)b->node)));
}

ListIter* func_001F2CC0(ListIter* it) {
    func_001F2CF0(it);
    return it;
}

ListIter* func_001F2CF0(ListIter* it) {
    ListIter_Next(it);
    return it;
}

/* Iterator increment: advance to the next node. */
ListIter* ListIter_Next(ListIter* it) {
    it->node = it->node->next;
    return it;
}

void func_001F2D40(void) {
    func_001F2D50();
}
