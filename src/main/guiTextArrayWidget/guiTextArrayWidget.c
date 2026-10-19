/*
 * main/guiTextArrayWidget: 8 files, 00425BB0-00425D10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00425BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */



int func_00425BB0(void) {
    return (int)"GuiTextArrayWidget";
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425BB0 */

/* merge_units: begin func_00425BC0 */
#pragma push /* merge_units */
char D_004BF900[] = "GuiTextArrayWidget"; /* "GuiTextArrayWidget" */

/* GuiTextArrayWidget::IsA: returns 1 if the given class name is "GuiTextArrayWidget". */
int GuiTextArrayWidget_IsType(void* self, const char* name)
{
    return strcmp(D_004BF900, name) == 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425BC0 */

/* merge_units: begin func_00425BF0 */
#pragma push /* merge_units */
#include "guiTextArrayWidget_types.h"

extern TextArrayCell* GuiTextArrayWidget_GetCell(guiTextArrayWidget* self, int row, int col);

/* Clears flag bit 2 of the addressed cell. */
void func_00425BF0(guiTextArrayWidget* self, int row, int col) {
    TextArrayCell* cell = GuiTextArrayWidget_GetCell(self, row, col);

    if (cell != 0) {
        cell->flags &= ~4;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425BF0 */

/* merge_units: begin func_00425C30 */
#pragma push /* merge_units */
typedef struct Node425 {
    char pad[0xC];
    int flags;
    char pad2[0x10];
    float value[4];
} Node425;

#if 0 /* merge_units */
extern Node425* GuiTextArrayWidget_GetCell(int a, int b, int c);
#endif /* merge_units */
#define GuiTextArrayWidget_GetCell(a0, a1, a2) ((Node425 *)GuiTextArrayWidget_GetCell((guiTextArrayWidget *)(a0), (a1), (a2))) /* merge_units */



/* Looks up a node and, if found, sets its 4-float value and flag bit 2. */
void func_00425C30(int a, int b, int c, float* value) {
    Node425* node = GuiTextArrayWidget_GetCell(a, b, c);
    if (node) {
        node->value[0] = value[0];
        node->value[1] = value[1];
        node->value[2] = value[2];
        node->value[3] = value[3];
        node->flags |= 4;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425C30(void) {}
#undef GuiTextArrayWidget_GetCell /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00425C30 */

/* merge_units: begin func_00425C90 */
#pragma push /* merge_units */
/* Clears flag bit 0 of the addressed cell. */
void func_00425C90(guiTextArrayWidget* self, int row, int col) {
    TextArrayCell* cell = GuiTextArrayWidget_GetCell(self, row, col);

    if (cell != 0) {
        cell->flags &= ~1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425C90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00425C90 */

/* merge_units: begin func_00425CD0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern TextArrayCell* GuiTextArrayWidget_GetCell(guiTextArrayWidget* widget, int row, int column);
#endif /* merge_units */
#define GuiTextArrayWidget_GetCell(a0, a1, a2) (GuiTextArrayWidget_GetCell((a0), (a1), (a2))) /* merge_units */


/* Set a cell's byte attribute and mark that attribute as present. */
void func_00425CD0(guiTextArrayWidget* widget, int row, int column, int attribute)
{
    TextArrayCell* cell = GuiTextArrayWidget_GetCell(widget, row, column);
    if (cell) {
        cell->attribute = attribute;
        cell->flags |= 1;
    }
}
#undef GuiTextArrayWidget_GetCell /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00425CD0 */

/* merge_units: begin func_00425D10 */
#pragma push /* merge_units */
extern void* Gui_GetScreenList(void);
extern int GuiFont_Find(void* strings, int id);

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
