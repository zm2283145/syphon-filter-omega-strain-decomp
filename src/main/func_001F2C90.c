/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int ListIter_NotEqual(ListIter*, ListIter*);
extern ListIter* std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(ListIter*);
extern ListIter* ListIter_Next(ListIter*);
extern void std_vector_cSkaSwitchItem_push_back(void);

int ListIter_NotEqual_Thunk_1F2C90(ListIter* a, ListIter* b) {
    return ListIter_NotEqual(a, b);
}

/* Iterator inequality. */
int ListIter_NotEqual(ListIter* a, ListIter* b) {
    return ((unsigned int)(0) < (unsigned int)(((int)a->node ^ (int)b->node)));
}

ListIter* cConstLListIterator_cSkaSwitchItemPtr_opInc(ListIter* it) {
    std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(it);
    return it;
}

ListIter* std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(ListIter* it) {
    ListIter_Next(it);
    return it;
}

/* Iterator increment: advance to the next node. */
ListIter* ListIter_Next(ListIter* it) {
    it->node = it->node->next;
    return it;
}

void cArray_cSkaSwitchItem_PushBackActual(void) {
    std_vector_cSkaSwitchItem_push_back();
}
