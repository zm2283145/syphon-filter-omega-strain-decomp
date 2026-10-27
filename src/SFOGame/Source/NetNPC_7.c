/*
 * SFOGame/Source/NetNPC: 1 file, 002D3900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D3900 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x30]; void* owner; } Obj2D3;

extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cNPC_RequestAction(Obj2D3* self, int a, int b);
extern void cNetNPCMsgs_SendMessage(void* owner, int type, int size, unsigned char a, int b, int c, int d);

/* Applies the change locally (unless suppressed by the global flags) and broadcasts it. */
void cNetNPC_RequestAction(Obj2D3* self, int a, int b)
{
    if (g_IsMultiplayer ? D_005721C0 : 1)
        cNPC_RequestAction(self, a, b);
    cNetNPCMsgs_SendMessage(self->owner, 0x14, 8, a, b, 0, 0);
}
static inline void merge_flush_func_002D3900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D3900 */
