/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_003B2630(char* self) {
    return self + 8;
}

int func_003B2640(int a0) {
    return ((unsigned int)(0) < (unsigned int)(*(unsigned char*)((char*)a0 + 22)));
}

void* func_003B2650(char* self) {
    return self + 4;
}

int func_003B2660(int a0) {
    return ((unsigned int)(0) < (unsigned int)(*(unsigned char*)((char*)a0 + 21)));
}

int func_003B2670(int a0) {
    return ((unsigned int)(0) < (unsigned int)(*(unsigned char*)((char*)a0 + 20)));
}

void* func_003B2680(void* self) {
    return self;
}

Iter16* SkaClip_AdvanceFrame16(Iter16* it) {
    it->p += 16;
    return it;
}
