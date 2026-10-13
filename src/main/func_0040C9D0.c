/*
 * Matched functions (byte-identical with the retail executable).
 * Object registry accessors; original translation unit not identified yet.
 */

#include "types.h"

extern int g_GobjRootScope;
/* Object registry (actor array). Declared as bytes: an int declaration changes
 * the register choice in Object_Register. */
extern char g_GobjWorldScope[];
extern int ObjRegistry_AppendRecursive(int registry, int obj);
extern void Object_SetRegistry(int obj, int registry);

/* Registers obj with the global registry (and its children, recursively). */
int Object_Register(int obj) {
    int registry;
    int ret;

    registry = *(int*)g_GobjWorldScope;
    Object_SetRegistry(obj, registry);
    ret = ObjRegistry_AppendRecursive(registry, obj);
    return ret;
}

int func_0040CA20(void) {
    return g_GobjRootScope;
}

int World_GetActorArray(void) {
    return *(int*)g_GobjWorldScope;
}
