/*
 * main/human: range (2 files, 001BA980-001BAB10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_001BA980 */
#pragma push /* merge_units */
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


typedef struct { char pad[0x24]; unsigned char type; char pad25[3]; float x; float y; } cNetShockMsg;

/* cNetShockMsg virtual 4: writes the type byte and two floats (raw bits) little-endian. */
void cNetShockMsg_v04(cNetShockMsg* self)
{
    float y;
    float x;
    *D_005061D0++ = self->type;
    x = self->x;
    write32(*(int*)&x);
    y = self->y;
    write32(*(int*)&y);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BA980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BA980 */

/* merge_units: begin func_001BAB10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004EF080;

/* Message type id. */
int cNetShockMsg_v05(void) {
    return D_004EF080;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BAB10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BAB10 */
