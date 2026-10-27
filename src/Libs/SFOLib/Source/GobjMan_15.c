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

/* Records the registry an object belongs to (called by nGobjManager_AddGOBJ). */
void cSystem_SetOwningList(L4RegObj* obj, int registry) {
    obj->registry = registry;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C990 */

/* merge_units: begin func_0040C9A0 */
#pragma push /* merge_units */
#include "GobjMan_types.h"

extern GobjScope* g_GobjWorldScope;
extern void cBaseObjList_Remove(GobjScope* registry, GobjEntry* object);

/* Submit a nonnull object's ID to the secondary registry. */
void nGobjManager_RemoveGOBJ(GobjEntry* object)
{
    if (object)
        cBaseObjList_Remove(g_GobjWorldScope, object);
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
 * the register choice in nGobjManager_AddGOBJ. */
#if 0 /* merge_units */
extern char g_GobjWorldScope[];
#endif /* merge_units */
#define g_GobjWorldScope ((char*)&g_GobjWorldScope) /* merge_units */

extern int cBaseObjList_Add(int registry, int obj);
#if 0 /* merge_units */
extern void cSystem_SetOwningList(int obj, int registry);
#endif /* merge_units */
#define cSystem_SetOwningList(a0, a1) (cSystem_SetOwningList((L4RegObj *)(a0), (a1))) /* merge_units */


/* Registers obj with the global registry (and its children, recursively). */
int nGobjManager_AddGOBJ(int obj) {
    int registry;
    int ret;

    registry = *(int*)g_GobjWorldScope;
    cSystem_SetOwningList(obj, registry);
    ret = cBaseObjList_Add(registry, obj);
    return ret;
}

int nGobjManager_GetGOBJAndNodeList(void) {
    return g_GobjRootScope;
}

int nGobjManager_GetGOBJList(void) {
    return *(int*)g_GobjWorldScope;
}
#undef g_GobjWorldScope /* merge_units */
#undef cSystem_SetOwningList /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040C9D0 */

/* merge_units: begin func_0040CA40 */
#pragma push /* merge_units */
/* Find an exact unsigned ID key, returning the map sentinel on failure. */
void std_tree_pair_cObjectId_value_compare_find(GobjMapNode** result, GobjMap* map, const GobjId* id)
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
extern void std_tree_pair_cObjectId_value_compare_destroy(Tree* t, int root);

/* Erases every node of the tree and resets it to empty. */
void std_tree_pair_cObjectId_value_compare_clear(Tree* t) {
    if (t->header != 0) {
        std_tree_pair_cObjectId_value_compare_destroy(t, t->header);
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
DEFINE_TREE_ERASE_ITER(std_tree_pair_cObjectId_value_compare_erase, std_red_black_tree_1_balance_erase, D_004BECF0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0040CB00 */
