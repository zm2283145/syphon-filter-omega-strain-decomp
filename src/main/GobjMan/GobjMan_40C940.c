#include "types.h"

extern void* g_GobjRootScope;
extern void Object_SetRegistry(void* obj, void* registry);
extern void ObjRegistry_AppendRecursive(void* registry, void* obj);

/* Attaches the object to the global registry and appends it recursively. */
void nGobjManager_AddNode(void* obj)
{
    void* registry;
    Object_SetRegistry(obj, registry = g_GobjRootScope);
    ObjRegistry_AppendRecursive(registry, obj);
}
