/*
 * SFOGame/Source/NetNPC: 1 file, 002D2F90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D2F90 */
#pragma push /* merge_units */
#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc2F90;
extern void cNPC_SetPickupable(Npc2F90* o, unsigned char v, int send);
void cNetNPC_SetPickupable(Npc2F90* o, unsigned char v, int send)
{
    if (send)
        cNetNPCMsgs_SendMessage(o->net, 0x21, 4, v, 0, 0, 0);
    cNPC_SetPickupable(o, v, 0);
}
static inline void merge_flush_func_002D2F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2F90 */
