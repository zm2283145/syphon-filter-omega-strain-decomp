/*
 * main/GuiScoresEquip: 4 files, 0035DE90-0035DF30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035DE90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vector_array_member_dtor.h"

/* Destructor: vector and array members, optionally delete. */
DEFINE_VECTOR_ARRAY_MEMBER_DTOR(func_0035DE90)
#pragma pop /* merge_units */
/* merge_units: end func_0035DE90 */

/* merge_units: begin func_0035DF30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiScoresEquip.cc. Functions are named by address
 * until real names are known.
 */


extern void* D_00533760;
extern int GuiScoresEquip_UpdateFigures(void* p);

int GuiScoresEquip_FigureCallback(void) {
    return GuiScoresEquip_UpdateFigures(D_00533760);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035DF30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035DF30 */

/* merge_units: begin func_0035DF40 */
#pragma push /* merge_units */
typedef struct { unsigned char flag : 1; unsigned char rest : 7; } FlagByte;
typedef struct { FlagByte b[16]; } FlagRow;
extern FlagRow* D_004EE620;

/* Clears flag bit 0 of byte [col] in row [row] of the global flag table. */
void TeamTable_ClearEnemy(int row, int col)
{
    D_004EE620[row].b[col].flag = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035DF40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035DF40 */

/* merge_units: begin func_0035DF70 */
#pragma push /* merge_units */
/* Byte of per-slot flags; bit 0 is the "set" flag. */
typedef struct SlotFlags {
    unsigned char set : 1;
} SlotFlags;

#if 0 /* merge_units */
extern char* D_004EE620; /* table of 16-byte rows of flag bytes */
#endif /* merge_units */
#define D_004EE620 (*(char **)&D_004EE620) /* merge_units */



/* Sets flag bit 0 of byte `col` in row `row` of the D_004EE620 table. */
void TeamTable_SetBit0(int row, int col) {
    SlotFlags* flags = (SlotFlags*)(D_004EE620 + row * 16 + col);
    flags->set = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035DF70(void) {}
#undef D_004EE620 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035DF70 */
