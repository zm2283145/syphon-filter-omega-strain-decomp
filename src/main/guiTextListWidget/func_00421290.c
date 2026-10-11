#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "guiTextWidget_types.h"

extern "C" {
void func_00298690(void* string);
GuiStreamString* String_CtorCStr_13B480(GuiStreamString* string, const char* text);
void func_0013D680(void* destination, const void* source);
void func_00138B70(void* string, int flags);
void func_00422A50(TextListEntryVec* entries, TextListEntry* position,
                   int count, const TextListEntry* value);
void func_00424430(TextRenderWidget* self, int first, int second);
void operator_delete(void* allocation);
}

/* Append an owned text entry and notify the list of its new row count. */
extern "C" int func_00421290(TextRenderWidget* self, const char* text,
                            int value, signed char style)
{
    if (!text)
        return 0;
    GuiStreamString temporary;
    TextListEntry entry;
    func_00298690(entry.text);
    String_CtorCStr_13B480(&temporary, text);
    func_0013D680(entry.text, &temporary);
    func_00138B70(&temporary, 0);
    entry.unk0C = value;
    entry.unk10 = style;
    func_00422A50(&self->entries, self->entries.data + self->entries.count, 1, &entry);
    ((TextListLayout*)self)->set_extent(1, self->entries.count);
    func_00424430(self, 0, 0);
    func_00138B70(entry.text, 0);
    return 1;
}

static inline void destroy_entry(TextListEntry* entry)
{
    if (entry)
        func_00138B70(entry->text, 0);
}

/* Destroy an entry's string before optionally freeing the entry itself. */
extern "C" TextListEntry* func_00421380(TextListEntry* self, short deleteFlag)
{
    if (self) {
        destroy_entry(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
