/*
 * SFOGame/Source/NetNPC: 2 files, 002D3BB0-002D3C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D3BB0 */
#pragma push /* merge_units */
#include "types.h"
#include "npc_auth.h"
typedef struct { char pad[0x30]; void* net; } Npc3BB0;
extern void cNPC_ActivateByRadiusOff(Npc3BB0* o);
void cNetNPC_ActivateByRadiusOff(Npc3BB0* o)
{
    if (NpcAuth_IsLocal())
        cNPC_ActivateByRadiusOff(o);
    cNetNPCMsgs_SendMessage(o->net, 0x34, 8, 0, 0, 0, 0);
}
static inline void merge_flush_func_002D3BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3BB0 */

/* merge_units: begin func_002D3C20 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* owner; } B5eObj;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cNPC_ActivateByRadius(B5eObj* o, float x);
#if 0 /* merge_units */
extern void cNetNPCMsgs_SendMessage(void* owner, int id, int size, unsigned int v, int a, int b, int c);
#endif /* merge_units */
#define cNetNPCMsgs_SendMessage(a0, a1, a2, a3, a4, a5, a6) (cNetNPCMsgs_SendMessage((a0), (a1), (a2), (int)(a3), (a4), (a5), (a6))) /* merge_units */

void cNetNPC_ActivateByRadius(B5eObj* o, float x) {
    if (g_IsMultiplayer ? D_005721C0 : 1) {
        cNPC_ActivateByRadius(o, x);
    }
    cNetNPCMsgs_SendMessage(o->owner, 0x33, 8, (unsigned int)x, 0, 0, 0);
}
#undef cNetNPCMsgs_SendMessage /* merge_units */
static inline void merge_flush_func_002D3C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3C20 */
