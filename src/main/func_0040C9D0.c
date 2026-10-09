/*
 * Matched functions (byte-identical with the retail executable).
 * Object registry accessors; original translation unit not identified yet.
 */

#include "types.h"

extern int D_00571740;
/* Object registry (actor array). Declared as bytes: an int declaration changes
 * the register choice in Object_Register. */
extern char D_00571748[];
extern int ObjRegistry_AppendRecursive(int registry, int obj);
extern void Object_SetRegistry(int obj, int registry);

/* Registers obj with the global registry (and its children, recursively). */
int Object_Register(int obj) {
    int registry;
    int ret;

    registry = *(int*)D_00571748;
    Object_SetRegistry(obj, registry);
    ret = ObjRegistry_AppendRecursive(registry, obj);
    return ret;
}

int func_0040CA20(void) {
    return D_00571740;
}

int World_GetActorArray(void) {
    return *(int*)D_00571748;
}
