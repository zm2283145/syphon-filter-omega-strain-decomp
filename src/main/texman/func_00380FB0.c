#include "types.h"

typedef struct { char pad[0x64]; int refs; } RefObj;
typedef struct { char pad[8]; RefObj** items; char pad2[4]; int count; } RefTable;

/* Increments the reference count of item index; returns 1 if the item exists. */
unsigned char func_00380FB0(RefTable* self, int index)
{
    unsigned char ok = 0;
    RefObj* obj;
    if (index >= 0 && index < self->count && (obj = self->items[index]) != 0) {
        obj->refs++;
        ok = 1;
    }
    return ok;
}
