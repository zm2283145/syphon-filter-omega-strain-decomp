/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_imp_cSkaBlendSequenceItem_ctor_vectorimpR(int, int);

int std_vector_cSkaBlendSequenceItem_ctor_vectorR(int a0, int a1) {
    std_vector_imp_cSkaBlendSequenceItem_ctor_vectorimpR(a0, a1);
    return a0;
}
