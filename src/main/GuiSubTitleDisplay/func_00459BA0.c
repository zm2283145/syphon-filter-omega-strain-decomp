/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiSubTitleDisplay.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_00459BA0(char* self) {
    return self + 4;
}

List* func_00459BB0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
