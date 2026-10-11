#pragma cplusplus on

#include "gui_grid_types.h"

extern "C" {
void func_00424430(GuiGridWidget* self, unsigned int column, unsigned int row);
void func_0041E040(GuiGridWidget* self, int message, unsigned int first, unsigned int second);
}

static inline unsigned char is_button_event(const GuiGridInput* input)
{
    unsigned char result = 0;
    if (input->type == 1 && input->device == 0)
        result = 1;
    return result;
}

static inline bool pressed(const GuiGridInput* input, unsigned short button)
{
    return input->type == 1 && input->device == 0 &&
           input->button == button && input->action == 0;
}

static inline void notify_change(GuiGridWidget* self, unsigned int column, unsigned int row)
{
    if (column != self->selectedColumn || row != self->selectedRow)
        func_0041E040(self, 16, 0, 0);
}

/* Handle grid confirmation and navigation while preserving boundary and wrap behavior. */
extern "C" int func_00423CC0(GuiGridWidget* self, const GuiGridInput* input)
{
    if (is_button_event(input)) {
        if (pressed(input, 0x40)) {
            func_0041E040(self, 16, 1, 0);
            func_0041E040(self, 19, self->selectedColumn, self->selectedRow);
            return 1;
        }
        unsigned int column = self->selectedColumn;
        unsigned int row = self->selectedRow;
        if (self->selectionMode != 1 && self->rows) {
            if (pressed(input, 0x1000)) {
                if (row)
                    func_00424430(self, column, row - 1);
                else if (self->wrapRows && self->rows > 1)
                    func_00424430(self, column, self->rows - 1);
                notify_change(self, column, row);
                return 1;
            }
            if (pressed(input, 0x4000)) {
                if (row != self->rows - 1)
                    func_00424430(self, column, row + 1);
                else if (self->wrapRows && self->rows > 1)
                    func_00424430(self, column, 0);
                notify_change(self, column, row);
                return 1;
            }
            if (self->pageNavigation) {
                if (pressed(input, 8)) {
                    if (self->rows && row && self->visibleRows > 1) {
                        int target = row - (self->visibleRows - 1);
                        if (target < 0) {
                            if (self->wrapRows)
                                target = self->rows - 1;
                            else
                                target = 0;
                        }
                        func_00424430(self, column, target);
                        notify_change(self, column, row);
                    }
                    return 1;
                }
                if (pressed(input, 4)) {
                    if (self->rows && row != self->rows - 1 && self->visibleRows > 1) {
                        unsigned int target = row + (self->visibleRows - 1);
                        if (target >= self->rows) {
                            if (self->wrapRows)
                                target = 0;
                            else
                                target = self->rows - 1;
                        }
                        func_00424430(self, column, target);
                        notify_change(self, column, row);
                    }
                    return 1;
                }
            }
        }
        if (self->selectionMode != 2 && self->columns) {
            /* Retail horizontal edge handling reselects the edge instead of wrapping. */
            if (pressed(input, 0x2000)) {
                if (column != self->columns - 1)
                    func_00424430(self, column + 1, row);
                else if (self->wrapRows && self->columns > 1)
                    func_00424430(self, self->columns - 1, row);
                notify_change(self, column, row);
                return 1;
            }
            if (pressed(input, 0x8000)) {
                if (column)
                    func_00424430(self, column - 1, row);
                else if (self->wrapRows && self->columns > 1)
                    func_00424430(self, 0, row);
                notify_change(self, column, row);
                return 1;
            }
        }
    }
    if (self->selectionMode != 1 && (pressed(input, 0x1000) || pressed(input, 0x4000)))
        return 1;
    if (self->selectionMode != 2 && (pressed(input, 0x8000) || pressed(input, 0x2000)))
        return 1;
    return 0;
}
