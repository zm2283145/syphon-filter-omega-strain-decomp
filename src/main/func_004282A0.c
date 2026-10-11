#pragma cplusplus on

#include "guiTextArrayWidget_types.h"

extern "C" {
TextArrayCell* func_004283C0(TextArrayCell* first, TextArrayCell* last,
                            TextArrayCell* destination);
void func_004267B0(TextArrayCell* cell, int flags);
}

/* Compact surviving cells, destroy the vacated tail and update the live count. */
extern "C" TextArrayCell* func_004282A0(TextArrayRow* self, TextArrayCell* first,
                                     TextArrayCell* last)
{
    if (first == last)
        return first;
    TextArrayCell* end = self->data + self->count;
    int tailCount = end - last;
    if (tailCount)
        func_004283C0(last, end, first);
    TextArrayCell* tail = first + tailCount;
    while (tail < end) {
        func_004267B0(tail, -1);
        ++tail;
    }
    self->count -= last - first;
    return first;
}

/* Copy cells forward with string ownership and aligned color assignment. */
extern "C" TextArrayCell* func_004283C0(TextArrayCell* first, TextArrayCell* last,
                                     TextArrayCell* destination)
{
    while (first < last) {
        copy_text_array_cell(destination, first);
        ++first;
        ++destination;
    }
    return destination;
}
