/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_004F7E50;
extern int* cMenuChoiceMsg_SOBJ_getClassId(void);

void* cMenuChoiceMsg_SOBJ_convert(void* self) {
    return self;
}

int* cMenuChoiceMsg_SOBJ_getClassId(void) {
    return &D_004F7E50;
}

int cMenuChoiceMsg_v03(void) {
    return *cMenuChoiceMsg_SOBJ_getClassId();
}
