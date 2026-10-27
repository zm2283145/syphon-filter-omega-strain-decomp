/*
 * SFOGame/Source/NetNPC: 1 file, 002D3CE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D3CE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

/* Sends message (id, 8, arg) to the owner. */
extern int cNetNPCMsgs_SendMessage(ControllerOwner* owner, int id, int kind, int arg, int a4, int a5, int a6);

int cNetNPC_SendNewAwarenessOfPlayers(Controller2D* self) {
    return cNetNPCMsgs_SendMessage(self->owner, 54, 8, 0, 0, 0, 0);
}
static inline void merge_flush_func_002D3CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3CE0 */
