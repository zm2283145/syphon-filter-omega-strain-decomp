/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void PtrVec_Insert(IndexedList* list, int* end, int n, void* arg);

void std_vector_tVUMNamePairPtr_push_back(IndexedList* list, void* arg) {
    PtrVec_Insert(list, list->base + list->count, 1, arg);
}
