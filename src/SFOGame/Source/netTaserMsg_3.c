/*
 * SFOGame/Source/netTaserMsg: 3 files, 0027BD30-0027BEC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027BD30 */
#pragma push /* merge_units */
#include "types.h"

extern unsigned char* D_005061D0; /* read cursor */

/* Reads a little-endian 16-bit value from the cursor. */
static inline short ReadShort(void) {
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

/* Reads a 32-bit float (as two 16-bit halves) from the cursor. */
float cNetMsg_GetFloat_void(void) {
    unsigned int bits;
    unsigned short low = ReadShort();
    unsigned short high = ReadShort();
    bits = low + (high << 16);
    return *(float*)&bits;
}
static inline void merge_flush_func_0027BD30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027BD30 */

/* merge_units: begin func_0027BDE0 */
#pragma push /* merge_units */
#pragma opt_dead_assignments off

typedef struct {
    char pad[0x24];
    unsigned char mode;
    char pad2[3];
    void* target;
    int a;
    unsigned char b;
    char pad3[3];
    int c;
    char pad4[8];
    float x, y, z;
} cNetTaserMsg;
extern void cNetMsg_PutGOBJ(void* target);
extern void cNetMsg_PutFloat(float f);

static inline void WriteU8(unsigned char v)
{
    *D_005061D0 = v;
    D_005061D0++;
}

/* cNetTaserMsg virtual 4: writes the mode; unless mode 2, also the target, position and three parameters. */
void cNetTaserMsg_Pack(cNetTaserMsg* self)
{
    WriteU8(self->mode);
    if (self->mode != 2) {
        cNetMsg_PutGOBJ(self->target);
        cNetMsg_PutFloat(self->x);
        cNetMsg_PutFloat(self->y);
        cNetMsg_PutFloat(self->z);
        WriteU8(self->a);
        WriteU8(self->b);
        WriteU8(self->c);
    }
}
static inline void merge_flush_func_0027BDE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027BDE0 */

/* merge_units: begin func_0027BEC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_00504070;

int cNetGrenadeMsg_GetMsgId(void) {
    return D_00504070;
}
static inline void merge_flush_func_0027BEC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027BEC0 */
