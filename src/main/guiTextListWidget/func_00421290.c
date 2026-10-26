#pragma cplusplus on

#include "guiTextListWidget_types.h"
#include "guiTextWidget_types.h"

extern "C" {
void String_CtorEmpty(void* string);
GuiStreamString* String_CtorCStr_13B480(GuiStreamString* string, const char* text);
void String_AssignString(void* destination, const void* source);
void String_Dtor(void* string, int flags);
void std_vector_imp_Item_insert(TextListEntryVec* entries, TextListEntry* position,
                   int count, const TextListEntry* value);
void GuiArrayWidget_Select(TextRenderWidget* self, int first, int second);
void operator_delete(void* allocation);
}

/* Append an owned text entry and notify the list of its new row count. */
extern "C" int GuiTextListWidget_AddItem(TextRenderWidget* self, const char* text,
                            int value, signed char style)
{
    if (!text)
        return 0;
    GuiStreamString temporary;
    TextListEntry entry;
    String_CtorEmpty(entry.text);
    String_CtorCStr_13B480(&temporary, text);
    String_AssignString(entry.text, &temporary);
    String_Dtor(&temporary, 0);
    entry.unk0C = value;
    entry.unk10 = style;
    std_vector_imp_Item_insert(&self->entries, self->entries.data + self->entries.count, 1, &entry);
    ((TextListLayout*)self)->set_extent(1, self->entries.count);
    GuiArrayWidget_Select(self, 0, 0);
    String_Dtor(entry.text, 0);
    return 1;
}

static inline void destroy_entry(TextListEntry* entry)
{
    if (entry)
        String_Dtor(entry->text, 0);
}

/* Destroy an entry's string before optionally freeing the entry itself. */
extern "C" TextListEntry* GuiTextListWidget_Item_dtor(TextListEntry* self, short deleteFlag)
{
    if (self) {
        destroy_entry(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
