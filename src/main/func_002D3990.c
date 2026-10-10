/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sends message (id, 8, arg) to the owner. */
extern int NetEvent_Send(ControllerOwner* owner, int id, int kind, int arg, int a4, int a5, int a6);

int func_002D3990(Controller2D* self, int arg) {
    return NetEvent_Send(self->owner, 56, 8, arg, 0, 0, 0);
}
