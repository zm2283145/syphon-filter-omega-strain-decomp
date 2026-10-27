/*
 * SFOGame/Source/NetNPC: 2 files, 002D3000-002D3040
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D3000 */
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

int cNetNPC_ChangeWeapon(Controller2D* self) {
    return cNetNPCMsgs_SendMessage(self->owner, 43, 8, 0, 0, 0, 0);
}

int cNetNPC_DrawWeapon(Controller2D* self, int arg) {
    return cNetNPCMsgs_SendMessage(self->owner, 32, 8, arg, 0, 0, 0);
}
static inline void merge_flush_func_002D3000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3000 */

/* merge_units: begin func_002D3040 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* owner; } S2D3040;
typedef struct { char pad[0xC]; int arg; } A2D3040;
#if 0 /* merge_units */
extern int cNetNPCMsgs_SendMessage(void* owner, int id, int kind, int arg, int a4, int a5, int a6);
#endif /* merge_units */
#define cNetNPCMsgs_SendMessage(a0, a1, a2, a3, a4, a5, a6) (cNetNPCMsgs_SendMessage((ControllerOwner *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */

void cNetNPC_SetGrenadeTarget(S2D3040* s, A2D3040* a, unsigned char c, float f)
{
    cNetNPCMsgs_SendMessage(s->owner, 0x1E, 8, a->arg, (int)f, c, 0);
}
#undef cNetNPCMsgs_SendMessage /* merge_units */
static inline void merge_flush_func_002D3040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3040 */
