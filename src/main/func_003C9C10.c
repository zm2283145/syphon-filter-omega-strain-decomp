/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int D_005435C0;

int func_003C9C10(void) {
    return D_005435C0;
}

int Event_GetType(Word* self) {
    return self[1].value;
}
