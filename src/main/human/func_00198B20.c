/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int func_00198B20(char* self) {
    return *(int*)(self + 0);
}

/* Address of 32-byte element i. */
char* func_00198B30(PtrVec* v, int i) {
    return (char*)v->data + (i << 5);
}

int func_00198B40(char* self) {
    return *(int*)(self + 4);
}

char* func_00198B50(Iter* it) {
    return (char*)it->p + 8;
}
