/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextArrayWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "guiTextArrayWidget_types.h"

extern TextArrayCell* func_00426590(guiTextArrayWidget* self, int row, int col);

/* Clears flag bit 2 of the addressed cell. */
void func_00425BF0(guiTextArrayWidget* self, int row, int col) {
    TextArrayCell* cell = func_00426590(self, row, col);

    if (cell != 0) {
        cell->flags &= ~4;
    }
}
