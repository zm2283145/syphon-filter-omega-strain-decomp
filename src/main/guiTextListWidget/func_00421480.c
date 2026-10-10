#include "guiTextListWidget_types.h"

static inline TextListEntry* entry_at(TextListWidget* self, int index)
{
    return &self->entries.data[index];
}

/* Return the entry's value, or -1 when the index is outside the list. */
int func_00421480(TextListWidget* self, int index)
{
    if (index < 0 || index >= self->entries.count)
        return -1;
    return entry_at(self, index)->unk0C;
}

/* Change the signed byte only for an existing list entry. */
void func_004214C0(TextListWidget* self, int index, signed char value)
{
    if (index < 0 || index >= self->entries.count)
        return;
    entry_at(self, index)->unk10 = value;
}

/* Preserve the distinct 255 sentinel for invalid indices. */
int func_00421500(TextListWidget* self, int index)
{
    if (index < 0 || index >= self->entries.count)
        return 255;
    return entry_at(self, index)->unk10;
}
