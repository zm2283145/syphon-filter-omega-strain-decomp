/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

AnimChannel* std_vector_cSkaSliderValue_opIndex(ChannelVec* v, int i) {
    return &v->data[i];
}
