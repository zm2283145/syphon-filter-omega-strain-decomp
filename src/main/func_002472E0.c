/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F7E50[];
extern int func_002472F0(void);

void* func_002472E0(void* self) {
    return self;
}

int func_002472F0(void) {
    return (int)D_004F7E50;
}

int cMenuChoiceMsg_v03(void) {
    int tmp0;
    int tmp2;

    tmp0 = func_002472F0();
    tmp2 = *(int*)(char*)tmp0;
    return tmp2;
}
