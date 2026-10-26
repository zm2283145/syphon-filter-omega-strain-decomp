/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul(void);

/* Address of the data pointer. */
char** std_vector_deleter_cSkaSwitchItem_data(ObjVec* v) {
    return &v->data;
}

void cConstLListIterator_cSkaSwitchItemPtr_opMul(void) {
    std_list_cSkaSwitchItemPtr_generic_iterator_1_opMul();
}
