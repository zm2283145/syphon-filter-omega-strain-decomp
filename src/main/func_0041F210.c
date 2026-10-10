#pragma cplusplus on

#include "guiTextWidget_types.h"

extern "C" {
GuiStreamString* String_CtorCStr_13B480(GuiStreamString* result, const char* text);
void func_0013D680(GuiStreamString* destination, const GuiStreamString* source);
void func_00138B70(GuiStreamString* string, int flags);
}

static inline const char* read_string(char** cursor)
{
    const char* start = *cursor;
    while (*(*cursor)++)
        ;
    return start;
}

static inline void read_flag(GuiWidgetStreamRecord* self, char** cursor, unsigned short mask)
{
    unsigned short enabled = *(unsigned short*)*cursor;
    *cursor += 2;
    if (enabled)
        self->flags |= mask;
    else
        self->flags &= ~mask;
}

/* Load the widget name, four aligned coordinates and two flag words. */
extern "C" int func_0041F210(GuiWidgetStreamRecord* self, char** cursor)
{
    GuiStreamString name;
    String_CtorCStr_13B480(&name, read_string(cursor));
    func_0013D680(&self->name, &name);
    func_00138B70(&name, 0);
    *cursor = (char*)(((unsigned int)*cursor + 3) & ~3u);
    self->first = *(float*)*cursor;
    *cursor += 4;
    self->second = *(float*)*cursor;
    *cursor += 4;
    self->third = *(float*)*cursor;
    *cursor += 4;
    self->fourth = *(float*)*cursor;
    *cursor += 4;
    read_flag(self, cursor, 2);
    read_flag(self, cursor, 4);
    return 1;
}
