#pragma cplusplus on

#include "gui_grid_types.h"

extern "C" {
void func_00424670(GuiGridWidget* self, unsigned int column, unsigned int row);
void func_0041EBA0(GuiGridWidget* widget, float x, float y);
void func_0043BC70(void* scrollbar, int first, unsigned int value, int minimum,
                   unsigned int maximum);
}

/* Notify selection changes, reveal the selected cell and update its indicators. */
extern "C" void func_00424430(GuiGridWidget* self, unsigned int column, unsigned int row)
{
    if (!self->columns && !self->rows) {
        self->selectedColumn = column;
        self->selectedRow = row;
    } else {
        if (column != self->selectedColumn || row != self->selectedRow) {
            self->on_deselected(self->selectedColumn, self->selectedRow);
            self->selectedColumn = column;
            self->selectedRow = row;
            self->on_selected(self->selectedColumn, self->selectedRow);
            if (!self->fixedViewport)
                func_00424670(self, self->selectedColumn, self->selectedRow);
        }
        if (self->marker && self->selectionMode == 2) {
            float y = self->y;
            y -= (float)((row - self->firstRow) * self->rowHeight);
            float excess = self->marker->height;
            excess -= (float)self->rowHeight;
            func_0041EBA0(self->marker, self->x, y + excess / 2.0f);
        }
        if (self->scrollbar)
            func_0043BC70(self->scrollbar, 0, self->selectedRow, 0, self->rows - 1);
    }
}

/* Test whether the cell lies inside the current viewport, unless it is fixed. */
extern "C" bool func_004245D0(GuiGridWidget* self, unsigned int column, unsigned int row)
{
    if (self->fixedViewport)
        return true;
    return column >= self->firstColumn &&
           column < self->firstColumn + self->visibleColumns &&
           row >= self->firstRow &&
           row < self->firstRow + self->visibleRows;
}

/* Move the viewport enough to include the cell and clamp its last visible row. */
extern "C" void func_00424670(GuiGridWidget* self, unsigned int column, unsigned int row)
{
    if (!self->fixedViewport) {
        if (column < self->firstColumn)
            self->firstColumn = column;
        else if (column >= self->firstColumn + self->visibleColumns)
            self->firstColumn = column - self->visibleColumns + 1;
        if (row < self->firstRow)
            self->firstRow = row;
        else if (row >= self->firstRow + self->visibleRows)
            self->firstRow = row - self->visibleRows + 1;
        if (self->rows < self->firstRow + self->visibleRows) {
            int first = self->rows - self->visibleRows;
            if (first < 0)
                first = 0;
            self->firstRow = first;
        }
    }
}
