/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern Rel* func_001B7A20(Rel*);

void func_001B79C0(char* self, float* value) {
    *(float*)(self + 16) = *value;
}

/* back(): address of the last 8-byte element. */
char* func_001B79D0(PtrVec* v) {
    return (char*)v->data + (v->count << 3) - 8;
}

/* Clear the three words and set the byte at +0x0C. */
Rel* func_001B79F0(Rel* r) {
    func_001B7A20(r);
    *((char*)r + 12) = 1;
    return r;
}
