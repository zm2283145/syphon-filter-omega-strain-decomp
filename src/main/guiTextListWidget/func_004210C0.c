#pragma cplusplus on

#include "guiTextListWidget_types.h"

extern "C" {
int func_00421280(TextListEntryVec* entries);
TextListEntry* func_00421260(TextListEntryVec* entries, int index);
TextListEntry* func_00421210(TextListEntry* destination, TextListEntry* source);
void func_004211C0(TextListEntryVec* entries);
void GuiArrayWidget_Select(TextRenderWidget* self, int first, int second);
}

static inline void erase_entry(TextListEntryVec* entries, int index)
{
    int count = func_00421280(entries);
    if (index >= 0 && index < count) {
        for (int next = index + 1; next < count; ++next) {
            TextListEntry* destination = func_00421260(entries, next - 1);
            TextListEntry* source = func_00421260(entries, next);
            func_00421210(destination, source);
        }
        func_004211C0(entries);
    }
}

/* Shift later entries over the removed row, then refresh the list's extent. */
extern "C" int GuiTextListWidget_RemoveItem(TextRenderWidget* self, int index)
{
    if (index < 0 || index >= self->entries.count)
        return 0;
    erase_entry(&self->entries, index);
    ((TextListLayout*)self)->set_extent(1, self->entries.count);
    GuiArrayWidget_Select(self, 0, 0);
    return 1;
}
