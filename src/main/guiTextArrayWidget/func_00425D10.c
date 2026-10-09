/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "guiTextArrayWidget_types.h"

extern void* func_00414790(void);
extern int func_00418420(void* strings, int id);
extern TextArrayCell* func_00426590(guiTextArrayWidget* self, int row, int col);

/* Clears flag bit 1 of the addressed cell. */
void func_00425D10(guiTextArrayWidget* self, int row, int col) {
    TextArrayCell* cell = func_00426590(self, row, col);

    if (cell != 0) {
        cell->flags &= ~2;
    }
}

/* Sets the text of the addressed cell from string id and marks it as having text. */
void func_00425D50(guiTextArrayWidget* self, int row, int col, int id) {
    TextArrayCell* cell = func_00426590(self, row, col);

    if (cell != 0) {
        cell->text = func_00418420(func_00414790(), id);
        cell->flags |= 2;
    }
}
