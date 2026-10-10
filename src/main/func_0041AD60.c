#include "types.h"

typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; char* longData; } SsoString;
typedef struct { char pad[0x48]; SsoString text; char pad2[0x24]; void* label; char pad3[4]; unsigned char showLength; } Widget41A;

extern void func_0041C3E0(Widget41A* self);
extern void func_0041AE90(void* label, int length);

/* Refreshes the widget and, if enabled, passes its text length to the label. */
void func_0041AD60(Widget41A* self)
{
    func_0041C3E0(self);
    if (self->showLength)
        func_0041AE90(self->label, (self->text.hdr.word & 1) ? self->text.longLen : (unsigned char)self->text.hdr.s.len);
}
