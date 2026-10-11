#pragma cplusplus on

#include "gui_grid_types.h"

extern "C" unsigned int func_004249A0(GuiGridWidget* self, unsigned int column);

/* Set the row height and recompute the number of complete visible rows. */
extern "C" void func_00424820(GuiGridWidget* self, unsigned int height)
{
    self->rowHeight = height;
    self->visibleRows = (unsigned int)(self->height / (float)self->rowHeight);
}

/* Let the last column consume remaining width, falling back to its requested size. */
extern "C" void func_004248C0(GuiGridWidget* self, unsigned int column, unsigned int width)
{
    if (column < self->columns - 1)
        self->columnWidths[column] = width;
    if (column == self->columns - 1) {
        int remaining = (int)self->width;
        for (unsigned int previous = 0; previous < self->columns - 1; ++previous)
            remaining -= func_004249A0(self, previous);
        self->columnWidths[column] = remaining > 0 ? remaining : width;
    }
}

/* Return a configured column width, or zero beyond the column count. */
extern "C" unsigned int func_004249A0(GuiGridWidget* self, unsigned int column)
{
    if (column >= self->columns)
        return 0;
    return self->columnWidths[column];
}
