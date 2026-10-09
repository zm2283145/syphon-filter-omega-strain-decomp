/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_002CE4C0(void) {
    return 1;
}

int func_002CE4D0(char* self) {
    return *(int*)(self + 0);
}

int func_002CE4E0(char* self) {
    return *(int*)(self + 4);
}

List* func_002CE4F0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
