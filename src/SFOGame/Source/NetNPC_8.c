/*
 * SFOGame/Source/NetNPC: 2 files, 002D3990-002D39B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D3990 */
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

int cNetNPC_SetHitPoints(Controller2D* self, int arg) {
    return cNetNPCMsgs_SendMessage(self->owner, 56, 8, arg, 0, 0, 0);
}
static inline void merge_flush_func_002D3990(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3990 */

/* merge_units: begin func_002D39B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; float f40; } NpcState;
typedef struct { char pad[0x30]; NpcState* state; } NpcObj;

/* Returns the NPC state float at +0x40 truncated to int. */
int cNetNPC_GetHitPoints(NpcObj* self)
{
    return (int)self->state->f40;
}
static inline void merge_flush_func_002D39B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D39B0 */
