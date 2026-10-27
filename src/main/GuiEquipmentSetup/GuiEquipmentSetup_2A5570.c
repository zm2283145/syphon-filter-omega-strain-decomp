/*
 * main/GuiEquipmentSetup: range (2 files, 002A5570-002A55A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002A5570 */
#pragma push /* merge_units */
/* Byte of per-slot flags; bit 0 is the "set" flag. */
typedef struct SlotFlags {
    unsigned char set : 1;
} SlotFlags;

extern char* D_004EE620; /* table of 16-byte rows of flag bytes */

/* Clears flag bit 0 of byte `col` in row `row` of the D_004EE620 table. */
void TeamDelEnemy_int_int(int row, int col) {
    SlotFlags* flags = (SlotFlags*)(D_004EE620 + row * 16 + col);
    flags->set = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A5570(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A5570 */

/* merge_units: begin func_002A55A0 */
#pragma push /* merge_units */
typedef struct CellFlags {
    unsigned char set : 1;
    unsigned char rest : 7;
} CellFlags;

typedef struct CellRow {
    CellFlags cells[16];
} CellRow;

#if 0 /* merge_units */
extern CellRow* D_004EE620;
#endif /* merge_units */
#define D_004EE620 (*(CellRow **)&D_004EE620) /* merge_units */


/* Marks cell (row, col) in the D_004EE620 grid. */
void TeamSetEnemy_int_int(int row, int col) {
    D_004EE620[row].cells[col].set = 1;
}
#undef D_004EE620 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002A55A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002A55A0 */
