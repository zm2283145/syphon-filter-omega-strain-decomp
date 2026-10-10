#include "types.h"

typedef struct { int value; } Handle;
typedef struct { int unk0; int unk4; int value; } HSrc;

/* Writes a handle holding the source's field at +8 to *out. */
void func_00183230(Handle* out, HSrc* s)
{
    Handle h;
    Handle tmp;
    tmp.value = s->value;
    h = tmp;
    out->value = h.value;
}
