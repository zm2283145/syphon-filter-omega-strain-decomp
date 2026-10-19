/*
 * main/game: range (2 files, 00131470-001314F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00131470 */
#pragma push /* merge_units */
typedef struct { char pad[5]; unsigned char v; } Cfg_1470;
typedef struct { char pad[0x67]; unsigned char on; char pad68[0x1DC - 0x68]; Cfg_1470* cfg; } S_1470;
typedef struct { char pad[0xC]; unsigned char flag; } G_1470;
extern unsigned char g_IsMultiplayer;
extern G_1470* g_Fader;
void PadRumble_Stop(void);
void Pad_EnableVibration(unsigned char v);
void Game_SetPaused(S_1470* self, unsigned char on)
{
    if (!g_IsMultiplayer)
        self->on = on;
    if (self->on) {
        PadRumble_Stop();
        Pad_EnableVibration(0);
        g_Fader->flag = 1;
    } else {
        Pad_EnableVibration(self->cfg->v);
        g_Fader->flag = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00131470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00131470 */

/* merge_units: begin func_001314F0 */
#pragma push /* merge_units */
int Agent_GetSelected(int a0, int a1) {
    int v0;
    int cond;

    v0 = 0 + -1;
    cond = a1 != v0;
    if (cond) goto L00131500;
    a1 = *(int*)((char*)a0 + 472);
L00131500:;
    v0 = a1 << 2;
    v0 = v0 + a0;
    v0 = *(int*)((char*)v0 + 456);
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001314F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001314F0 */
