/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int std_opNe_listdeleterR_listdeleterR(ListIter*, ListIter*);
extern ListIter* std_list_deleter_voidPtr_generic_iterator_1_opInc(ListIter*);
extern ListIter* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(ListIter*);
extern void std_vector_cSkaBlendSequenceItem_push_back(void);

int std_opNe_listR_listR_3(ListIter* a, ListIter* b) {
    return std_opNe_listdeleterR_listdeleterR(a, b);
}

ListIter* cConstLListIterator_cSkaBlendSequenceItemPtr_opInc(ListIter* it) {
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(it);
    return it;
}

ListIter* std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opInc(ListIter* it) {
    std_list_deleter_voidPtr_generic_iterator_1_opInc(it);
    return it;
}

void cArray_cSkaBlendSequenceItem_PushBackActual(void) {
    std_vector_cSkaBlendSequenceItem_push_back();
}
