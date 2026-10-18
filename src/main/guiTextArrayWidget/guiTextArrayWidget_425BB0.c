/*
 * main/guiTextArrayWidget: range (5 files, 00425BB0-00425C90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strcmp(const void *, const void *);

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
#define GuiTextArrayWidget_GetCell(a0, a1, a2) ((Node425 *)GuiTextArrayWidget_GetCell((void *)(a0), (a1), (a2))) /* merge_units */


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
#undef GuiTextArrayWidget_GetCell /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00425C30(void) {}
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
