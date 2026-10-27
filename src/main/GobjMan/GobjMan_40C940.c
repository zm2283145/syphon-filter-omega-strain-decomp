#include "types.h"

extern void* g_GobjRootScope;
extern void cSystem_SetOwningList(void* obj, void* registry);
extern void cBaseObjList_Add(void* registry, void* obj);

/* Attaches the object to the global registry and appends it recursively. */
void nGobjManager_AddNode(void* obj)
{
    void* registry;
    cSystem_SetOwningList(obj, registry = g_GobjRootScope);
    cBaseObjList_Add(registry, obj);
}
