/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodebaseP(int* self, int value) {
    *self = value;
    return self;
}

int* std_list_deleter_cSafePtr_cGOBJ_generic_iterator_ctor_nodeP(int* self, int value) {
    *self = value;
    return self;
}

void* std_list_deleter_cSafePtr_cGOBJ_tail(char* self) {
    return self + 4;
}
