/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opMul(void);

/* Address of the data pointer. */
char** std_vector_deleter_cSkaBlendSequenceItem_data_void(ObjVec* v) {
    return &v->data;
}

void cConstLListIterator_cSkaBlendSequenceItemPtr_opMul(void) {
    std_list_cSkaBlendSequenceItemPtr_generic_iterator_1_opMul();
}
