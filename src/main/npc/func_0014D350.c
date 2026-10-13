#include "types.h"

typedef struct { char pad[0xC]; int serial; } Tracked;
typedef struct { Tracked* obj; int serial; } WeakRef;

/* Returns the referenced object if it is still the same instance (serial matches), else 0. */
Tracked* Handle_Resolve(WeakRef* self)
{
    Tracked* obj = self->obj;
    unsigned char valid = 1;
    if ((!obj) == 0 && obj->serial != self->serial)
        valid = 0;
    return valid ? obj : 0;
}
