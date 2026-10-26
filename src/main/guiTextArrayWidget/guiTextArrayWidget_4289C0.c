/*
 * main/guiTextArrayWidget: 4 files, 004289C0-00428C20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004289C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_51(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004289C0 */

/* merge_units: begin func_00428A00 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "guiTextArrayWidget_types.h"

extern "C" void GuiTextArrayWidget_tTextElement_dtor(TextArrayCell* cell, int flags);

/* Fill an existing cell range with independently owned string values. */
extern "C" void std_fill_n_tTextElement_int_fill_n(TextArrayCell* destination, unsigned int count,
                            const TextArrayCell* value)
{
    while (count) {
        copy_text_array_cell(destination, value);
        --count;
        ++destination;
    }
}

/* Copy cells backward to preserve overlapping source ranges. */
extern "C" TextArrayCell* std_copy_backward_tTextElement_copy_backward(TextArrayCell* first, TextArrayCell* last,
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
extern "C" void std_vector_deleter_tTextElement_clear(TextArrayRow* self)
{
    TextArrayCell* first = self->data;
    TextArrayCell* end = first + self->count;
    while (first < end) {
        --end;
        GuiTextArrayWidget_tTextElement_dtor(end, -1);
    }
    self->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00428A00 */

/* merge_units: begin func_00428B90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_copy_ctor.h"

/* Copy-construct a string. */
DEFINE_SHORT_STRING_COPY_CTOR(func_00428B90)
#pragma pop /* merge_units */
/* merge_units: end func_00428B90 */

/* merge_units: begin func_00428C20 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate and construct. */
extern "C" { char D_004BF868[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_CTOR(GuiTextArrayWidget_Create, 0xC0, D_004BF868, guiTextArrayWidget_ctor)
#pragma pop /* merge_units */
/* merge_units: end func_00428C20 */
