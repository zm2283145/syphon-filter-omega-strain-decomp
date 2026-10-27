/*
 * main/human: range (2 files, 001B99E0-001B9AA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_001B99E0 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

/* Writes a float to the network stream as its 32-bit pattern, little-endian. */
void cNetMsg_PutFloat(float f)
{
    int bits = *(int*)&f;
    write16((unsigned short)bits);
    write16(bits >> 16);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B99E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B99E0 */

/* merge_units: begin func_001B9AA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004EEED8;

/* Message type id. */
int cNetThrowStarMsg_GetMsgId(void) {
    return D_004EEED8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B9AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B9AA0 */
