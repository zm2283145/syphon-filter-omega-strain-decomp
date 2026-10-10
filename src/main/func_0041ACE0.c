#include "loose04_types.h"

extern int func_0041C560(Unk41ADC0* self, char** cursor);

/* Read the widget's trailing word and flag after its base fields. */
int func_0041ACE0(Unk41ADC0* self, char** cursor)
{
    unsigned short enabled;
    if (!func_0041C560(self, cursor))
        return 0;
    self->unk84 = *(int*)*cursor;
    *cursor += 4;
    enabled = *(unsigned short*)*cursor;
    *cursor += 2;
    self->unk80 = enabled != 0;
    return 1;
}
