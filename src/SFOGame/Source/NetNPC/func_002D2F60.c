/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sends message (id, 8, arg) to the owner. */
extern int cNetNPCMsgs_SendMessage(ControllerOwner* owner, int id, int kind, int arg, int a4, int a5, int a6);

int cNetNPC_Kill(Controller2D* self) {
    return cNetNPCMsgs_SendMessage(self->owner, 25, 8, 0, 0, 0, 0);
}

void cNetNPC_SetDarkness(void) {
}
