/*
 * main/guiTextArrayWidget: range (2 files, 00425D10-00425DB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00425D10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "guiTextArrayWidget_types.h"

extern void* Gui_GetScreenList(void);
extern int GuiFont_Find(void* strings, int id);
extern TextArrayCell* GuiTextArrayWidget_GetCell(guiTextArrayWidget* self, int row, int col);

/* Clears flag bit 1 of the addressed cell. */
void func_00425D10(guiTextArrayWidget* self, int row, int col) {
    TextArrayCell* cell = GuiTextArrayWidget_GetCell(self, row, col);

    if (cell != 0) {
        cell->flags &= ~2;
    }
}

/* Sets the text of the addressed cell from string id and marks it as having text. */
void func_00425D50(guiTextArrayWidget* self, int row, int col, int id) {
    TextArrayCell* cell = GuiTextArrayWidget_GetCell(self, row, col);

    if (cell != 0) {
        cell->text = GuiFont_Find(Gui_GetScreenList(), id);
        cell->flags |= 2;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425D10 */

/* merge_units: begin func_00425DB0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } Vec4f;
typedef struct { char pad[0x90]; void* target; char pad2[0xC]; Vec4f color; } Obj;
extern void TextObj_SetColour(void* target, Vec4f* color);

/* Stores a colour and pushes it to the attached target. */
void func_00425DB0(Obj* self, Vec4f* color)
{
    self->color.x = color->x;
    self->color.y = color->y;
    self->color.z = color->z;
    self->color.w = color->w;
    if (self->target) {
        TextObj_SetColour(self->target, &self->color);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425DB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425DB0 */
