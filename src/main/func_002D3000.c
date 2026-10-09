/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sends message (id, 8, arg) to the owner. */
extern int func_002D7290(ControllerOwner* owner, int id, int kind, int arg, int a4, int a5, int a6);

int func_002D3000(Controller2D* self) {
    return func_002D7290(self->owner, 43, 8, 0, 0, 0, 0);
}

int func_002D3020(Controller2D* self, int arg) {
    return func_002D7290(self->owner, 32, 8, arg, 0, 0, 0);
}
