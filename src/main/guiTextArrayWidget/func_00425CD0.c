#include "guiTextArrayWidget_types.h"

extern TextArrayCell* func_00426590(guiTextArrayWidget* widget, int row, int column);

/* Set a cell's byte attribute and mark that attribute as present. */
void func_00425CD0(guiTextArrayWidget* widget, int row, int column, int attribute)
{
    TextArrayCell* cell = func_00426590(widget, row, column);
    if (cell) {
        cell->attribute = attribute;
        cell->flags |= 1;
    }
}
