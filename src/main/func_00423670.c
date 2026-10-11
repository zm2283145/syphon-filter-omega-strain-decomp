#pragma cplusplus on

#include "gui_grid_types.h"

extern "C" {
int func_00423BE0(GuiGridWidget* self, unsigned int visibleRow);
void func_0041E470(GuiGridWidget* self);
}

/* Draw visible column backgrounds, row backgrounds and cells before drawing children. */
extern "C" void func_00423670(GuiGridWidget* self)
{
    GuiGridRect columnRect;
    GuiGridRect rowRect;
    GuiGridRect cellRect;
    float height = (float)(self->rowHeight * self->visibleRows);
    float x = self->x;
    for (unsigned int column = 0; column < self->visibleColumns; ++column) {
        columnRect.x = x;
        columnRect.y = self->y;
        columnRect.width = self->columns == 1 ? self->width :
            (float)(int)self->columnWidths[column + self->firstColumn];
        columnRect.height = height;
        if (column + self->firstColumn >= self->columns)
            break;
        self->draw_column(column + self->firstColumn, &columnRect);
        x += (float)(int)self->columnWidths[column + self->firstColumn];
    }

    float y = self->y;
    float width = 0.0f;
    for (unsigned int column = 0; column < self->visibleColumns; ++column)
        width += (float)(int)self->columnWidths[column + self->firstColumn];

    for (unsigned int row = 0; row < self->visibleRows; ++row) {
        rowRect.x = self->x;
        rowRect.y = y;
        rowRect.width = width;
        rowRect.height = (float)self->rowHeight;
        if (self->fixedViewport) {
            int mappedRow = func_00423BE0(self, row);
            if (mappedRow >= 0)
                self->draw_row(mappedRow, &rowRect);
        } else {
            if (row + self->firstRow >= self->rows)
                break;
            self->draw_row(row + self->firstRow, &rowRect);
        }
        y -= (float)self->rowHeight;
    }

    float cellY = self->y;
    for (unsigned int row = 0; row < self->visibleRows; ++row) {
        float cellX = self->x;
        for (unsigned int column = 0; column < self->visibleColumns; ++column) {
            cellRect.x = cellX;
            cellRect.y = cellY;
            cellRect.width = self->columns == 1 ? self->width :
                (float)(int)self->columnWidths[column + self->firstColumn];
            cellRect.height = (float)self->rowHeight;
            if (self->fixedViewport) {
                int mappedRow = func_00423BE0(self, row);
                if (mappedRow >= 0)
                    self->draw_cell(column + self->firstColumn, mappedRow, &cellRect);
            } else {
                self->draw_cell(column + self->firstColumn, row + self->firstRow, &cellRect);
            }
            cellX += (float)(int)self->columnWidths[column + self->firstColumn];
        }
        cellY -= (float)self->rowHeight;
    }
    func_0041E470(self);
}

static inline int magnitude(int value)
{
    return value > 0 ? value : -value;
}

/* Map a fixed-viewport row around the selection, wrapping only when it fits. */
extern "C" int func_00423BE0(GuiGridWidget* self, unsigned int visibleRow)
{
    int offset = visibleRow - self->centerRow;
    int row = offset + self->selectedRow;
    if (row >= 0 && (unsigned int)row < self->rows)
        return row;
    if (self->wrapRows) {
        if (row < 0) {
            if (self->visibleRows - self->centerRow + magnitude(offset) <= self->rows)
                row += self->rows;
        } else {
            if (self->visibleRows - self->centerRow + magnitude(offset) <= self->rows)
                row -= self->rows;
        }
        if (row >= 0 && (unsigned int)row < self->rows)
            return row;
    }
    return -1;
}
