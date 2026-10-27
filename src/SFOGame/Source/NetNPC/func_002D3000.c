/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sends message (id, 8, arg) to the owner. */
extern int cNetNPCMsgs_SendMessage(ControllerOwner* owner, int id, int kind, int arg, int a4, int a5, int a6);

int cNetNPC_ChangeWeapon(Controller2D* self) {
    return cNetNPCMsgs_SendMessage(self->owner, 43, 8, 0, 0, 0, 0);
}

int cNetNPC_DrawWeapon(Controller2D* self, int arg) {
    return cNetNPCMsgs_SendMessage(self->owner, 32, 8, arg, 0, 0, 0);
}
