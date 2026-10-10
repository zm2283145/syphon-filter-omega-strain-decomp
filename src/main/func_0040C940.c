#include "types.h"

extern void* D_00571740;
extern void Object_SetRegistry(void* obj, void* registry);
extern void ObjRegistry_AppendRecursive(void* registry, void* obj);

/* Attaches the object to the global registry and appends it recursively. */
void func_0040C940(void* obj)
{
    void* registry;
    Object_SetRegistry(obj, registry = D_00571740);
    ObjRegistry_AppendRecursive(registry, obj);
}
