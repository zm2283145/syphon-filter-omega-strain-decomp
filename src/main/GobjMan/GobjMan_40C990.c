/*
 * main/GobjMan: 6 files, 0040C990-0040CB00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040C990 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Records the registry an object belongs to (called by Object_Register). */
void Object_SetRegistry(L4RegObj* obj, int registry) {
    obj->registry = registry;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C990 */

/* merge_units: begin func_0040C9A0 */
#pragma push /* merge_units */
#include "GobjMan_types.h"

extern GobjScope* g_GobjWorldScope;
extern void ActorWorld_RequestRemove(GobjScope* registry, GobjEntry* object);

/* Submit a nonnull object's ID to the secondary registry. */
void Object_Unregister(GobjEntry* object)
{
    if (object)
        ActorWorld_RequestRemove(g_GobjWorldScope, object);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C9A0 */

/* merge_units: begin func_0040C9D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Object registry accessors; original translation unit not identified yet.
 */


extern int g_GobjRootScope;
/* Object registry (actor array). Declared as bytes: an int declaration changes
 * the register choice in Object_Register. */
#if 0 /* merge_units */
extern char g_GobjWorldScope[];
#endif /* merge_units */
#define g_GobjWorldScope ((char*)&g_GobjWorldScope) /* merge_units */

extern int ObjRegistry_AppendRecursive(int registry, int obj);
#if 0 /* merge_units */
extern void Object_SetRegistry(int obj, int registry);
#endif /* merge_units */
#define Object_SetRegistry(a0, a1) (Object_SetRegistry((L4RegObj *)(a0), (a1))) /* merge_units */


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
#undef g_GobjWorldScope /* merge_units */
#undef Object_SetRegistry /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040C9D0 */

/* merge_units: begin func_0040CA40 */
#pragma push /* merge_units */
/* Find an exact unsigned ID key, returning the map sentinel on failure. */
void ObjMap_Find(GobjMapNode** result, GobjMap* map, const GobjId* id)
{
    GobjMapNode* node = map->root;
    GobjMapNode* candidate = (GobjMapNode*)&map->root;
    while (node) {
        if (!(node->key < id->word)) {
            candidate = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (candidate == (GobjMapNode*)&map->root || id->word < candidate->key)
        *result = (GobjMapNode*)&map->root;
    else
        *result = candidate;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040CA40 */

/* merge_units: begin func_0040CAC0 */
#pragma push /* merge_units */
extern void func_0040CD10(Tree* t, int root);

/* Erases every node of the tree and resets it to empty. */
void func_0040CAC0(Tree* t) {
    if (t->header != 0) {
        func_0040CD10(t, t->header);
        t->unk0 = 0;
        t->header = 0;
        t->leftmost = &t->header;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040CAC0 */

/* merge_units: begin func_0040CB00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_erase_iter.h"

extern "C" { char D_004BECF0[] = "allocator.hh"; }
DEFINE_TREE_ERASE_ITER(func_0040CB00, func_0013C800, D_004BECF0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0040CB00 */
