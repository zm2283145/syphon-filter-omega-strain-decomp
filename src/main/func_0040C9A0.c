#include "GobjMan_types.h"

extern GobjScope* g_GobjWorldScope;
extern void func_0040B720(GobjScope* registry, GobjEntry* object);

/* Submit a nonnull object's ID to the secondary registry. */
void Object_Unregister(GobjEntry* object)
{
    if (object)
        func_0040B720(g_GobjWorldScope, object);
}
