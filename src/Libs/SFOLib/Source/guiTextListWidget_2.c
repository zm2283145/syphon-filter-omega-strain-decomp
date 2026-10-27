/*
 * Libs/SFOLib/Source/guiTextListWidget: 1 file, 004210C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004210C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "guiTextListWidget_types.h"

extern "C" {
int cArray_Item_Size(TextListEntryVec* entries);
TextListEntry* std_vector_Item_opIndex(TextListEntryVec* entries, int index);
TextListEntry* GuiTextListWidget_Item_opAssign(TextListEntry* destination, TextListEntry* source);
void cArray_Item_PopBack(TextListEntryVec* entries);
void GuiArrayWidget_SetSelected(TextRenderWidget* self, int first, int second);
}

static inline void erase_entry(TextListEntryVec* entries, int index)
{
    int count = cArray_Item_Size(entries);
    if (index >= 0 && index < count) {
        for (int next = index + 1; next < count; ++next) {
            TextListEntry* destination = std_vector_Item_opIndex(entries, next - 1);
            TextListEntry* source = std_vector_Item_opIndex(entries, next);
            GuiTextListWidget_Item_opAssign(destination, source);
        }
        cArray_Item_PopBack(entries);
    }
}

/* Shift later entries over the removed row, then refresh the list's extent. */
extern "C" int GuiTextListWidget_RemoveItem(TextRenderWidget* self, int index)
{
    if (index < 0 || index >= self->entries.count)
        return 0;
    erase_entry(&self->entries, index);
    ((TextListLayout*)self)->set_extent(1, self->entries.count);
    GuiArrayWidget_SetSelected(self, 0, 0);
    return 1;
}
static inline void merge_flush_func_004210C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004210C0 */
