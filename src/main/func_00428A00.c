#pragma cplusplus on

#include "guiTextArrayWidget_types.h"

extern "C" void func_004267B0(TextArrayCell* cell, int flags);

/* Fill an existing cell range with independently owned string values. */
extern "C" void func_00428A00(TextArrayCell* destination, unsigned int count,
                            const TextArrayCell* value)
{
    while (count) {
        copy_text_array_cell(destination, value);
        --count;
        ++destination;
    }
}

/* Copy cells backward to preserve overlapping source ranges. */
extern "C" TextArrayCell* func_00428A80(TextArrayCell* first, TextArrayCell* last,
                                     TextArrayCell* destinationEnd)
{
    while (first < last) {
        --last;
        --destinationEnd;
        copy_text_array_cell(destinationEnd, last);
    }
    return destinationEnd;
}

/* Destroy live cells in reverse order, then reset the count. */
extern "C" void func_00428B10(TextArrayRow* self)
{
    TextArrayCell* first = self->data;
    TextArrayCell* end = first + self->count;
    while (first < end) {
        --end;
        func_004267B0(end, -1);
    }
    self->count = 0;
}
