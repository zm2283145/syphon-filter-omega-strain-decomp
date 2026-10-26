/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "taser_types.h"

/* &v->data[i] */
TaserEntry* std_vector_TaserPoint_opIndex(TaserVec* v, int i) {
    return &v->data[i];
}
