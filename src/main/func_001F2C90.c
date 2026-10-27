/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int std_opNe_listdeleterR_listdeleterR(ListIter*, ListIter*);
extern ListIter* std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(ListIter*);
extern ListIter* std_list_deleter_voidPtr_generic_iterator_1_opInc(ListIter*);
extern void std_vector_cSkaSwitchItem_push_back(void);

int std_opNe_listR_listR(ListIter* a, ListIter* b) {
    return std_opNe_listdeleterR_listdeleterR(a, b);
}

/* Iterator inequality. */
int std_opNe_listdeleterR_listdeleterR(ListIter* a, ListIter* b) {
    return ((unsigned int)(0) < (unsigned int)(((int)a->node ^ (int)b->node)));
}

ListIter* cConstLListIterator_cSkaSwitchItemPtr_opInc(ListIter* it) {
    std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(it);
    return it;
}

ListIter* std_list_cSkaSwitchItemPtr_generic_iterator_1_opInc(ListIter* it) {
    std_list_deleter_voidPtr_generic_iterator_1_opInc(it);
    return it;
}

/* Iterator increment: advance to the next node. */
ListIter* std_list_deleter_voidPtr_generic_iterator_1_opInc(ListIter* it) {
    it->node = it->node->next;
    return it;
}

void cArray_cSkaSwitchItem_PushBackActual(void) {
    std_vector_cSkaSwitchItem_push_back();
}
