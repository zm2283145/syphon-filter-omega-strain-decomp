/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cSkaSystem_RequestTransition_CrossFadeInDuration(char* self) {
    return self + 60;
}

int cPointer_cSkaNode_opMul(char* self) {
    return *(int*)(self + 0);
}

void* func_001ADD60(char* self) {
    return self + 48;
}

void* func_001ADD70(char* self) {
    return self + 36;
}

int cSkaSystem_RequestTransition_HasAnim(char* self) {
    return *(unsigned int*)(self + 48) != 0;
}
