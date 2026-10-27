/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void std_vector_cSkaBlendSequenceItem_reserve(void);
extern void std_vector_deleter_cSkaBlendSequenceItem_clear(int);

void std_vector_imp_cSkaBlendSequenceItem_clear(int a0) {
    std_vector_deleter_cSkaBlendSequenceItem_clear(a0);
}

void cArray_cSkaBlendSequenceItem_ReserveActual(void) {
    std_vector_cSkaBlendSequenceItem_reserve();
}
