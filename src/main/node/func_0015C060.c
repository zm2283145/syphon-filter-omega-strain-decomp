#include "types.h"

typedef struct Object { char pad[0x58]; struct Object* attached; } Object;

/* Returns the object's attached object, or the object itself when none. */
Object* Object_GetAttachedOrSelf(Object* o)
{
    if (o->attached)
        return o->attached;
    return o;
}
