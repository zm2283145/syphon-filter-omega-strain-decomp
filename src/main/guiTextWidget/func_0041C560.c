#include "guiTextWidget_types.h"

extern int func_0041F210(GuiWidgetStreamRecord* self, char** cursor);
extern void func_0041BEB0(GuiTextStreamRecord* self, const char* text, int localized);
extern void* func_00414790(void);
extern int func_00418420(void* manager, const char* name);

static inline const char* read_string(char** cursor)
{
    const char* start = *cursor;
    while (*(*cursor)++)
        ;
    return start;
}

/* Load two strings, align the stream, and read the text widget's numeric fields. */
int func_0041C560(GuiTextStreamRecord* self, char** cursor)
{
    const char* resource;
    if (!func_0041F210(&self->base, cursor))
        return 0;
    func_0041BEB0(self, read_string(cursor), 1);
    resource = read_string(cursor);
    self->resource = func_00418420(func_00414790(), resource);
    *cursor = (char*)(((unsigned int)*cursor + 3) & ~3u);
    self->first = *(float*)*cursor;
    *cursor += 4;
    self->second = *(float*)*cursor;
    *cursor += 4;
    self->third = *(float*)*cursor;
    *cursor += 4;
    self->scale = 1.0f;
    self->value = *(int*)*cursor;
    *cursor += 4;
    return 1;
}
