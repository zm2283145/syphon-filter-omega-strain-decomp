/*
 * main/tank: 2 files, 002821A0-00282240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002821A0 */
#pragma push /* merge_units */
#include "types.h"

extern unsigned char* D_005061D0; /* read cursor */

/* Reads a little-endian 16-bit value from the cursor. */
static inline short ReadShort(void) {
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

/* Reads two 16-bit halves from the cursor and stores them as one 32-bit word. */
void Script_ReadU32(unsigned int* out) {
    unsigned short low = ReadShort();
    unsigned short high = ReadShort();
    *out = low + (high << 16);
}
#pragma pop /* merge_units */
/* merge_units: end func_002821A0 */

/* merge_units: begin func_00282240 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { short a; short b; char c[0x100]; } Proto_00282240;
extern char D_005061C8[];
extern void func_002822F0(void);

NETREG_BEGIN(func_00282240, Proto_00282240)
NETREG_FIELD(b, 2, 1)
NETREG_FIELD(a, 2, 1)
NETREG_FIELD(c, 1, 0x100)
NETREG_END(D_005061C8, func_002822F0)
#pragma pop /* merge_units */
/* merge_units: end func_00282240 */
