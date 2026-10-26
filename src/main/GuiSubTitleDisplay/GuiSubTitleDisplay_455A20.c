/*
 * main/GuiSubTitleDisplay: 5 files, 00455A20-00455C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00455A20 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
char *Loc_LookupText(char *);                             
int GuiTextArrayWidget_SetCellText(int, int, int, char *);                  
int sprintf(char *, char *, int);                             
extern char D_004C1A38;
extern char D_004C1A40;
extern char D_004C1A50;

void GuiWeaponStats_SetItemStats(int arg0, int arg1) {
    int sp40[4];
    int var_s0;

    var_s0 = 0;
    do {
        GuiTextArrayWidget_SetCellText(arg0, 0, var_s0, &D_004C1A38);
        GuiTextArrayWidget_SetCellText(arg0, 1, var_s0, &D_004C1A38);
        var_s0 += 1;
    } while (var_s0 < 3);
    GuiTextArrayWidget_SetCellText(arg0, 0, 2, Loc_LookupText(&D_004C1A40));
    sprintf(sp40, &D_004C1A50, arg1);
    GuiTextArrayWidget_SetCellText(arg0, 1, 2, sp40);
}
#pragma pop /* merge_units */
/* merge_units: end func_00455A20 */

/* merge_units: begin func_00455AE0 */
#pragma push /* merge_units */
extern char D_00587D50[];
extern char D_00587D60[];
extern void TextArrayCell_SetColour(void* self, const char* name);
extern void GuiTextArrayWidget_DrawCell(void* self, void* data, int a, int b);
/* Sets the name (depending on whether data is given), then initialises with data. */
void GuiWeaponStats_CellColour(void* self, void* data, int a, int b)
{
    TextArrayCell_SetColour(self, data == 0 ? D_00587D50 : D_00587D60);
    GuiTextArrayWidget_DrawCell(self, data, a, b);
}
#pragma pop /* merge_units */
/* merge_units: end func_00455AE0 */

/* merge_units: begin func_00455B60 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Menu: only the slots used here are named (vtable offset in comments). */
struct Menu {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a, int b); /* +0x5C */
};

extern "C" void GuiTextArrayWidget_Init(Menu* self);
extern "C" void GuiArrayWidget_ColumnWidth(Menu* self, int column, int width);
extern "C" void GuiTextArrayWidget_SetFont(Menu* self, const char* name);
extern "C" void GuiTextArrayWidget_SetHAlign(Menu* self, int value);
extern "C" void GuiWeaponStats_Fill(Menu* self, int index);

/* Menu setup: base init, virtual +0x5C(2, 4), two column widths, the "callout" name, then GuiWeaponStats_Fill(-1). */
extern "C" void GuiWeaponStats_Init(Menu* self)
{
    GuiTextArrayWidget_Init(self);
    self->Method5C(2, 4);
    GuiArrayWidget_ColumnWidth(self, 0, 0x73);
    GuiArrayWidget_ColumnWidth(self, 1, 10);
    GuiTextArrayWidget_SetFont(self, "callout");
    GuiTextArrayWidget_SetHAlign(self, 0);
    GuiWeaponStats_Fill(self, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_00455B60 */

/* merge_units: begin func_00455BF0 */
#pragma push /* merge_units */
typedef struct { unsigned char flag : 1; unsigned char rest : 7; } FlagByte;
typedef struct { FlagByte b[16]; } FlagRow;
extern FlagRow* D_004EE620;

/* Clears flag bit 0 of byte [col] in row [row] of the global flag table. */
void TeamDelEnemy_int_int_3(int row, int col)
{
    D_004EE620[row].b[col].flag = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00455BF0 */

/* merge_units: begin func_00455C20 */
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
void TeamTable_SetBit0_455C20(int row, int col) {
    SlotFlags* flags = (SlotFlags*)(D_004EE620 + row * 16 + col);
    flags->set = 1;
}
#undef D_004EE620 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00455C20 */
