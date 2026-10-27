/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int GuiWidget_onAdvanceTime(void* self, float dt);

int* std_list_deleter_TextAtom_generic_iterator_ctor(int* self, int value) {
    *self = value;
    return self;
}

void* std_list_deleter_TextAtom_tail(char* self) {
    return self + 4;
}

void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_12(void* self) {
    return self;
}

/* Update: calls the base update, then advances the timer at +0x54 by dt/30. */
int GuiSubTitleDisplay_onAdvanceTime(char* self, float dt) {
    int result = GuiWidget_onAdvanceTime(self, dt);

    *(float*)(self + 84) = *(float*)(self + 84) + dt / 30.0f;
    return result;
}
