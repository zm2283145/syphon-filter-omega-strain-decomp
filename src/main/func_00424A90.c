#pragma cplusplus on

#include "gui_grid_types.h"

extern "C" {
void func_0041EFA0(GuiGridWidget* self);
void func_004248C0(GuiGridWidget* self, unsigned int column, unsigned int width);
}

/* Reset selection, refresh visible dimensions and notify the initial selected cell. */
extern "C" void func_00424A90(GuiGridWidget* self)
{
    func_0041EFA0(self);
    self->selectedColumn = 0;
    self->selectedRow = 0;
    self->visibleRows = (unsigned int)(self->height / (float)self->rowHeight);
    if (self->columns == 1)
        func_004248C0(self, 0, (unsigned int)self->width);
    self->on_selected(self->selectedColumn, self->selectedRow);
}
