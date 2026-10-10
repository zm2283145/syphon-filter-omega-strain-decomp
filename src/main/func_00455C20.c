#include "types.h"

/* Byte of per-slot flags; bit 0 is the "set" flag. */
typedef struct SlotFlags {
    unsigned char set : 1;
} SlotFlags;

extern char* D_004EE620; /* table of 16-byte rows of flag bytes */

/* Sets flag bit 0 of byte `col` in row `row` of the D_004EE620 table. */
void func_00455C20(int row, int col) {
    SlotFlags* flags = (SlotFlags*)(D_004EE620 + row * 16 + col);
    flags->set = 1;
}
