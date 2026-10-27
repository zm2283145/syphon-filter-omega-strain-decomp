/*
 * SFOGame/Source/NetNPC: 4 files, 002D2D50-002D2EE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D2D50 */
#pragma push /* merge_units */
#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0xC]; int id; } Tgt2D2D50;
typedef struct { char pad[0x30]; void* net; } Npc2D2D50;
extern void cNPC_Follow_cGOBJP_float_float(Npc2D2D50* o, Tgt2D2D50* t, float a, float b);
void cNetNPC_Follow(Npc2D2D50* o, Tgt2D2D50* t, float a, float b)
{
    if (NpcAuth_IsLocal()) cNPC_Follow_cGOBJP_float_float(o, t, a, b);
    cNetNPCMsgs_SendMessage(o->net, 0x32, 8, t->id, *(int*)&a, *(int*)&b, 0);
}
static inline void merge_flush_func_002D2D50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2D50 */

/* merge_units: begin func_002D2DE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc2DE0;
typedef struct { char pad[0x78]; int netId; } Node2DE0;
extern void cNPC_RemoveGroupFromPathRegion(Npc2DE0* o, Node2DE0* n);
void cNetNPC_RemoveGroupFromPathRegion(Npc2DE0* o, Node2DE0* n)
{
    if (NpcAuth_IsLocal())
        cNPC_RemoveGroupFromPathRegion(o, n);
    cNetNPCMsgs_SendMessage(o->net, 0x31, 8, *(volatile int*)&n->netId, 0, 0, 0);
}
static inline void merge_flush_func_002D2DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2DE0 */

/* merge_units: begin func_002D2E60 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc2E60;
typedef struct { char pad[0x78]; int netId; } Node2E60;
extern void cNPC_AddGroupToPathRegion(Npc2E60* o, Node2E60* n);
void cNetNPC_AddGroupToPathRegion(Npc2E60* o, Node2E60* n)
{
    if (NpcAuth_IsLocal())
        cNPC_AddGroupToPathRegion(o, n);
    cNetNPCMsgs_SendMessage(o->net, 0x30, 8, *(volatile int*)&n->netId, 0, 0, 0);
}
static inline void merge_flush_func_002D2E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2E60 */

/* merge_units: begin func_002D2EE0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc2EE0;
typedef struct { char pad[0x78]; int netId; } Node2EE0;
extern void cNPC_RestrictMovementToNodeGroup(Npc2EE0* o, Node2EE0* n);
void cNetNPC_RestrictMovementToNodeGroup(Npc2EE0* o, Node2EE0* n)
{
    if (NpcAuth_IsLocal())
        cNPC_RestrictMovementToNodeGroup(o, n);
    cNetNPCMsgs_SendMessage(o->net, 0x2F, 8, *(volatile int*)&n->netId, 0, 0, 0);
}
static inline void merge_flush_func_002D2EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2EE0 */
