/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* cSkaSystem_RequestTransition_CrossFadeDuration(char* self) {
    return self + 60;
}

void* cSkaSystem_RequestTransition_CrossFadeOutDuration(char* self) {
    return self + 76;
}

void* cSkaSystem_RequestTransition_EndOfTransitionCallback(char* self) {
    return self + 92;
}
