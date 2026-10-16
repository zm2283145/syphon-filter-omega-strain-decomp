#include "guiTextListWidget_types.h"

extern void TextObj_SetColour(TextRenderChild* child, const TextRenderStyle* style);
extern const char* String_CStr(const void* string);
extern void TextObj_SetText(TextRenderChild* child, const char* text);
extern void TextObj_Draw(TextRenderChild* child);
extern void func_00423600(TextRenderWidget* self, void* context, unsigned int index,
                          const TextRenderRect* rect);

static inline TextListEntry* entry_at(TextRenderWidget* self, unsigned int index)
{
    return &self->entries.data[index];
}

static inline void set_position(TextRenderChild* child, float x, float y)
{
    int top = (int)y;
    int left = (int)x;
    child->x = left;
    child->y = top;
}

static inline void set_size(TextRenderChild* child, float width, float height)
{
    int rows = (int)height;
    int columns = (int)width;
    child->width = columns;
    child->height = rows;
}

/* Render an existing text row with its selected or per-entry style, then its base. */
void func_00420E50(TextRenderWidget* self, void* context, unsigned int index,
                   const TextRenderRect* rect)
{
    if (self->child && index < (unsigned int)self->entries.count) {
        if (index == self->selected && self->highlighted)
            TextObj_SetColour(self->child, &self->highlight);
        else
            TextObj_SetColour(self->child,
                         &self->styles[(unsigned char)entry_at(self, index)->unk10]);
        set_position(self->child, rect->x, rect->y);
        set_size(self->child, rect->width, rect->height);
        TextObj_SetText(self->child, String_CStr(entry_at(self, index)));
        TextObj_Draw(self->child);
    }
    func_00423600(self, context, index, rect);
}
