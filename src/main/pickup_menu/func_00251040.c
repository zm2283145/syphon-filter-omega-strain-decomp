/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "pickup_menu_types.h"

extern char D_004F7E70[];
extern float func_003D0810(PickupMenu* self, char* arg);

float func_00251040(PickupMenu* self) {
    self->unk10 = 1;
    self->unk11 = 1;
    return func_003D0810(self, D_004F7E70);
}
