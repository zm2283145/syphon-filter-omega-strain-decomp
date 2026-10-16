/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GuiWidget_Update(void* self, float dt);

int* func_00457FB0(int* self, int value) {
    *self = value;
    return self;
}

void* func_00457FC0(char* self) {
    return self + 4;
}

void* func_00457FD0(void* self) {
    return self;
}

/* Update: calls the base update, then advances the timer at +0x54 by dt/30. */
int GuiSubTitleDisplay_Update(char* self, float dt) {
    int result = GuiWidget_Update(self, dt);

    *(float*)(self + 84) = *(float*)(self + 84) + dt / 30.0f;
    return result;
}
