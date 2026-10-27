/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cGameSystem_IsNetworked(void) {
    return 1;
}

void* cSystem_ScriptGetObjectId(char* self) {
    return self + 12;
}

void* cSystem_ScriptGetRealObj(void* self) {
    return self;
}

int cSystem_SendCreated(void) {
    return 1;
}

void cSystem_NetActivate(void) {
}

void cSystem_NetDeactivate(void) {
}

void cSystem_NetEnable(void) {
}

void cSystem_NetDisable(void) {
}

int cSystem_IsDeliverable(void) {
    return 1;
}
