/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int ListIter_NotEqual(ListIter*, ListIter*);
extern ListIter* ListIter_Next(ListIter*);
extern ListIter* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(ListIter*);
extern void std_vector_cSkaBlendSequenceItem_push_back(void);

int ListIter_NotEqual_Thunk_1F4030(ListIter* a, ListIter* b) {
    return ListIter_NotEqual(a, b);
}

ListIter* cConstLListIterator_cSkaBlendSequenceItemPtr_opInc(ListIter* it) {
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(it);
    return it;
}

ListIter* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(ListIter* it) {
    ListIter_Next(it);
    return it;
}

void cArray_cSkaBlendSequenceItem_PushBackActual(void) {
    std_vector_cSkaBlendSequenceItem_push_back();
}
