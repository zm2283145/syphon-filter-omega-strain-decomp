/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_vector_deleter_tParTimes_clear(char* self) {
    *(int*)(self + 4) = 0;
}

void std_vector_deleter_RatingRecord_clear(char* self) {
    *(int*)(self + 4) = 0;
}

void std_vector_deleter_tRankInfo_clear(char* self) {
    *(int*)(self + 4) = 0;
}

void std_vector_deleter_PartData_clear(char* self) {
    *(int*)(self + 4) = 0;
}
