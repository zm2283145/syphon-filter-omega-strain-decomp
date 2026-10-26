/*
 * main/guiTextListWidget: 12 files, 00423670-00424A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00423670 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "gui_grid_types.h"

extern "C" {
int GuiArrayWidget_VisibleRowToRow(GuiGridWidget* self, unsigned int visibleRow);
void GuiWidget_Draw(GuiGridWidget* self);
}

/* Draw visible column backgrounds, row backgrounds and cells before drawing children. */
extern "C" void GuiArrayWidget_Draw(GuiGridWidget* self)
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
            int mappedRow = GuiArrayWidget_VisibleRowToRow(self, row);
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
                int mappedRow = GuiArrayWidget_VisibleRowToRow(self, row);
                if (mappedRow >= 0)
                    self->draw_cell(column + self->firstColumn, mappedRow, &cellRect);
            } else {
                self->draw_cell(column + self->firstColumn, row + self->firstRow, &cellRect);
            }
            cellX += (float)(int)self->columnWidths[column + self->firstColumn];
        }
        cellY -= (float)self->rowHeight;
    }
    GuiWidget_Draw(self);
}

static inline int magnitude(int value)
{
    return value > 0 ? value : -value;
}

/* Map a fixed-viewport row around the selection, wrapping only when it fits. */
extern "C" int GuiArrayWidget_VisibleRowToRow(GuiGridWidget* self, unsigned int visibleRow)
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
#pragma pop /* merge_units */
/* merge_units: end func_00423670 */

/* merge_units: begin func_00423CC0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void GuiArrayWidget_Select(GuiGridWidget* self, unsigned int column, unsigned int row);
void GuiWidget_SendEventUp(GuiGridWidget* self, int message, unsigned int first, unsigned int second);
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
        GuiWidget_SendEventUp(self, 16, 0, 0);
}

/* Handle grid confirmation and navigation while preserving boundary and wrap behavior. */
extern "C" int GuiArrayWidget_OnInput(GuiGridWidget* self, const GuiGridInput* input)
{
    if (is_button_event(input)) {
        if (pressed(input, 0x40)) {
            GuiWidget_SendEventUp(self, 16, 1, 0);
            GuiWidget_SendEventUp(self, 19, self->selectedColumn, self->selectedRow);
            return 1;
        }
        unsigned int column = self->selectedColumn;
        unsigned int row = self->selectedRow;
        if (self->selectionMode != 1 && self->rows) {
            if (pressed(input, 0x1000)) {
                if (row)
                    GuiArrayWidget_Select(self, column, row - 1);
                else if (self->wrapRows && self->rows > 1)
                    GuiArrayWidget_Select(self, column, self->rows - 1);
                notify_change(self, column, row);
                return 1;
            }
            if (pressed(input, 0x4000)) {
                if (row != self->rows - 1)
                    GuiArrayWidget_Select(self, column, row + 1);
                else if (self->wrapRows && self->rows > 1)
                    GuiArrayWidget_Select(self, column, 0);
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
                        GuiArrayWidget_Select(self, column, target);
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
                        GuiArrayWidget_Select(self, column, target);
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
                    GuiArrayWidget_Select(self, column + 1, row);
                else if (self->wrapRows && self->columns > 1)
                    GuiArrayWidget_Select(self, self->columns - 1, row);
                notify_change(self, column, row);
                return 1;
            }
            if (pressed(input, 0x8000)) {
                if (column)
                    GuiArrayWidget_Select(self, column - 1, row);
                else if (self->wrapRows && self->columns > 1)
                    GuiArrayWidget_Select(self, 0, row);
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
#pragma pop /* merge_units */
/* merge_units: end func_00423CC0 */

/* merge_units: begin func_00424410 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Assumed to be the GuiWidget424C50 class (nearby constructor, matching offsets). */
void GuiArrayWidget_GetSelected(GuiWidget424C50* self, int* outA, int* outB) {
    *outA = self->unk50;
    *outB = self->unk54;
}
#pragma pop /* merge_units */
/* merge_units: end func_00424410 */

/* merge_units: begin func_00424430 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void GuiArrayWidget_Scroll(GuiGridWidget* self, unsigned int column, unsigned int row);
void GuiWidget_SetPos(GuiGridWidget* widget, float x, float y);
void GuiScrollBarWidget_SetRange(void* scrollbar, int first, unsigned int value, int minimum,
                   unsigned int maximum);
}

/* Notify selection changes, reveal the selected cell and update its indicators. */
extern "C" void GuiArrayWidget_Select(GuiGridWidget* self, unsigned int column, unsigned int row)
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
                GuiArrayWidget_Scroll(self, self->selectedColumn, self->selectedRow);
        }
        if (self->marker && self->selectionMode == 2) {
            float y = self->y;
            y -= (float)((row - self->firstRow) * self->rowHeight);
            float excess = self->marker->height;
            excess -= (float)self->rowHeight;
            GuiWidget_SetPos(self->marker, self->x, y + excess / 2.0f);
        }
        if (self->scrollbar)
            GuiScrollBarWidget_SetRange(self->scrollbar, 0, self->selectedRow, 0, self->rows - 1);
    }
}

/* Test whether the cell lies inside the current viewport, unless it is fixed. */
extern "C" bool GuiArrayWidget_IsCellVisible(GuiGridWidget* self, unsigned int column, unsigned int row)
{
    if (self->fixedViewport)
        return true;
    return column >= self->firstColumn &&
           column < self->firstColumn + self->visibleColumns &&
           row >= self->firstRow &&
           row < self->firstRow + self->visibleRows;
}

/* Move the viewport enough to include the cell and clamp its last visible row. */
extern "C" void GuiArrayWidget_Scroll(GuiGridWidget* self, unsigned int column, unsigned int row)
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
#pragma pop /* merge_units */
/* merge_units: end func_00424430 */

/* merge_units: begin func_00424730 */
#pragma push /* merge_units */
/* Assumed to be the GuiWidget424C50 class (nearby constructor, matching offsets). */
void GuiArrayWidget_GetSize(GuiWidget424C50* self, int* outA, int* outB) {
    *outA = self->unk48;
    *outB = self->unk4C;
}
#pragma pop /* merge_units */
/* merge_units: end func_00424730 */

/* merge_units: begin func_00424750 */
#pragma push /* merge_units */
typedef struct { char pad[0x48]; unsigned int n48; int f4c; int f50; int f54; char pad2[8]; char vec[4]; int f64; char pad3[8]; int f70; char pad4[0x18]; void* f8c; } O424;
extern void PtrVec_PushBack_1C1080(void*, char*);
#if 0 /* merge_units */
extern void GuiScrollBarWidget_SetRange(void*, int, int, int, int);
#endif /* merge_units */
#define GuiScrollBarWidget_SetRange(a0, a1, a2, a3, a4) (GuiScrollBarWidget_SetRange((a0), (a1), (unsigned int)(a2), (a3), (unsigned int)(a4))) /* merge_units */

void GuiArrayWidget_SetDims(O424* o, int a, int b) {
    o->n48 = a;
    o->f4c = b;
    o->f70 = a;
    if (a != o->f64) {
        unsigned int i;
        o->f64 = 0;
        for (i = 0; i < o->n48; i++) PtrVec_PushBack_1C1080(o->vec, "<");
    }
    if (o->f8c) GuiScrollBarWidget_SetRange(o->f8c, 0, o->f54, 0, o->f4c - 1);
}
#undef GuiScrollBarWidget_SetRange /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00424750 */

/* merge_units: begin func_00424800 */
#pragma push /* merge_units */
extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int value);

/* push_back. */
int func_00424800(PtrVec* v, int value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_00424800 */

/* merge_units: begin func_00424820 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" unsigned int GuiArrayWidget_GetColumnWidth(GuiGridWidget* self, unsigned int column);

/* Set the row height and recompute the number of complete visible rows. */
extern "C" void GuiArrayWidget_RowHeight(GuiGridWidget* self, unsigned int height)
{
    self->rowHeight = height;
    self->visibleRows = (unsigned int)(self->height / (float)self->rowHeight);
}

/* Let the last column consume remaining width, falling back to its requested size. */
extern "C" void GuiArrayWidget_ColumnWidth(GuiGridWidget* self, unsigned int column, unsigned int width)
{
    if (column < self->columns - 1)
        self->columnWidths[column] = width;
    if (column == self->columns - 1) {
        int remaining = (int)self->width;
        for (unsigned int previous = 0; previous < self->columns - 1; ++previous)
            remaining -= GuiArrayWidget_GetColumnWidth(self, previous);
        self->columnWidths[column] = remaining > 0 ? remaining : width;
    }
}

/* Return a configured column width, or zero beyond the column count. */
extern "C" unsigned int GuiArrayWidget_GetColumnWidth(GuiGridWidget* self, unsigned int column)
{
    if (column >= self->columns)
        return 0;
    return self->columnWidths[column];
}
#pragma pop /* merge_units */
/* merge_units: end func_00424820 */

/* merge_units: begin func_004249D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Widget {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19();
    virtual void Method70(int a, int b); /* +0x70 */
    char pad04[0x50 - 4];
    int unk50; /* +0x50 */
    int unk54; /* +0x54 */
};

extern "C" void GuiWidget_BubbleType1(Widget* self);

/* GuiWidget_BubbleType1 then virtual slot +0x70 with fields +0x50/+0x54. */
extern "C" void GuiArrayWidget_OnLoseFocus(Widget* self)
{
    GuiWidget_BubbleType1(self);
    self->Method70(self->unk50, self->unk54);
}
#pragma pop /* merge_units */
/* merge_units: end func_004249D0 */

/* merge_units: begin func_00424A10 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Widget: only the slots used here are named (vtable offset in comments). */
struct Widget_00424A10 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18();
    virtual void Method6C(int a, int b); /* +0x6C */
    char pad04[0x50 - 4];
    int unk50; /* +0x50 */
    int unk54; /* +0x54 */
};

extern "C" void GuiWidget_BubbleType0(Widget_00424A10* self);

/* Runs GuiWidget_BubbleType0, then the virtual at vtable+0x6C with the two words at +0x50/+0x54. */
extern "C" void GuiArrayWidget_OnGainFocus(Widget_00424A10* self)
{
    GuiWidget_BubbleType0(self);
    self->Method6C(self->unk50, self->unk54);
}
#pragma pop /* merge_units */
/* merge_units: end func_00424A10 */

/* merge_units: begin func_00424A50 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


extern "C" void GuiWidget_BaseSleep(Widget* self);

/* Runs GuiWidget_BaseSleep, then virtual +0x70 with the words at +0x50/+0x54. */
extern "C" void GuiArrayWidget_Sleep(Widget* self)
{
    GuiWidget_BaseSleep(self);
    self->Method70(self->unk50, self->unk54);
}
#pragma pop /* merge_units */
/* merge_units: end func_00424A50 */

/* merge_units: begin func_00424A90 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
void GuiWidget_BaseWake(GuiGridWidget* self);
#if 0 /* merge_units */
void GuiArrayWidget_ColumnWidth(GuiGridWidget* self, unsigned int column, unsigned int width);
#endif /* merge_units */
#define GuiArrayWidget_ColumnWidth(a0, a1, a2) ((void)GuiArrayWidget_ColumnWidth((a0), (a1), (a2))) /* merge_units */

}

/* Reset selection, refresh visible dimensions and notify the initial selected cell. */
extern "C" void GuiArrayWidget_OnWake(GuiGridWidget* self)
{
    GuiWidget_BaseWake(self);
    self->selectedColumn = 0;
    self->selectedRow = 0;
    self->visibleRows = (unsigned int)(self->height / (float)self->rowHeight);
    if (self->columns == 1)
        GuiArrayWidget_ColumnWidth(self, 0, (unsigned int)self->width);
    self->on_selected(self->selectedColumn, self->selectedRow);
}
#undef GuiArrayWidget_ColumnWidth /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00424A90 */
