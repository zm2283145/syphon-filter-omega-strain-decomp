/*
 * SFOGame/Source/NetNPC: 4 files, 002D39D0-002D3B10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D39D0 */
#pragma push /* merge_units */
#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; char pad2[0xE8]; int i11C; int i120; char pad3[0x19]; unsigned char b13D; } Npc39D0;
void cNetNPC_ResumeAIAiming(Npc39D0* o)
{
    if (NpcAuth_IsLocal()) {
        o->i120 = 0;
        o->b13D = 1;
        o->i11C = -1;
    }
    cNetNPCMsgs_SendMessage(o->net, 0xB, 8, 0, 0, 0, 0);
}
static inline void merge_flush_func_002D39D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D39D0 */

/* merge_units: begin func_002D3A30 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; char pad2[0xE8]; int i11C; } Npc3A30;
void cNetNPC_SetAimSubtarget(Npc3A30* o, signed char v)
{
    if (NpcAuth_IsLocal())
        o->i11C = v;
    cNetNPCMsgs_SendMessage(o->net, 0xA, 8, v, 0, 0, 0);
}
static inline void merge_flush_func_002D3A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3A30 */

/* merge_units: begin func_002D3A90 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc3A90;
extern void cNPC_SetAimMode_eAimMode(Npc3A90* o, unsigned char v);
void cNetNPC_SetAimMode(Npc3A90* o, unsigned char v)
{
    if (NpcAuth_IsLocal())
        cNPC_SetAimMode_eAimMode(o, v);
    cNetNPCMsgs_SendMessage(o->net, 9, 8, v, 0, 0, 0);
}
static inline void merge_flush_func_002D3A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3A90 */

/* merge_units: begin func_002D3B10 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* net; } Npc2D3B10;
extern void cNPC_SetAggressiveness(Npc2D3B10* o, float v);
void cNetNPC_SetAggressiveness(Npc2D3B10* o, float v)
{
    if (NpcAuth_IsLocal()) cNPC_SetAggressiveness(o, v);
    cNetNPCMsgs_SendMessage(o->net, 8, 8, *(int*)&v, 0, 0, 0);
}
static inline void merge_flush_func_002D3B10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3B10 */
