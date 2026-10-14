/*
 * main/GuiGameOptions: range (2 files, 0029BE20-0029BF70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0029BE20 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int player; int reason; } cNetKickMsg;

extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void write32(int v)
{
    write16((unsigned short)v);
    write16(v >> 16);
}

/* cNetKickMsg virtual 4: writes the player and reason as 32-bit little-endian values. */
void cNetKickMsg_v04(cNetKickMsg* self)
{
    write32(self->player);
    write32(self->reason);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BE20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BE20 */

/* merge_units: begin func_0029BF70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiGameOptions.cc. Functions are named by address
 * until real names are known.
 */


extern int D_00506448;

int cNetKickMsg_v05(void) {
    return D_00506448;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029BF70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029BF70 */
