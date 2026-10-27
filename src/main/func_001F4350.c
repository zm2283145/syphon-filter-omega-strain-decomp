/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_list_imp_voidPtr_size(void);
extern int std_vector_imp_cSkaBlendSequenceItem_reserve(int, int);

int std_vector_cSkaBlendSequenceItem_reserve(int a0, int a1) {
    return std_vector_imp_cSkaBlendSequenceItem_reserve(a0, a1);
}

int cLList_cSkaBlendSequenceItemPtr_Size(void) {
    return std_list_imp_voidPtr_size();
}
