/*
 * main/player: 3 files, 0040B6D0-0040B790
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040B6D0 */
#pragma push /* merge_units */
#include "GobjMan_types.h"

extern GobjMap D_00571C10;
extern GobjMapNode D_00571C14;
extern void ObjMap_Find(GobjMapNode** result, GobjMap* map, const GobjId* id);

/* Find the object associated with an ID in the global registry map. */
GobjEntry* ObjRegistry_Find(GobjScope* unused, const GobjId* id)
{
    GobjMapNode* node;
    ObjMap_Find(&node, &D_00571C10, id);
    if (node == &D_00571C14)
        return 0;
    return node->object;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040B6D0 */

/* merge_units: begin func_0040B720 */
#pragma push /* merge_units */
#include "types.h"

typedef struct RegNode { struct RegNode* parent; char pad[0x10]; int list; int index; int* items; } RegNode;
extern void KeyVector_PushBack(int* list, int* where, int n, void* item);

/* Inserts the item into this node's list and every ancestor's. */
void ActorWorld_RequestRemove(RegNode* self, char* item)
{
    if (item) {
        KeyVector_PushBack(&self->list, self->items + self->index, 1, item + 0xC);
        if (self->parent) {
            ActorWorld_RequestRemove(self->parent, item);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040B720 */

/* merge_units: begin func_0040B790 */
#pragma push /* merge_units */
typedef struct Obj40B790 { char pad[0xC]; int key; } Obj40B790;
typedef struct Node40B790 { struct Node40B790* parent; char list[4]; } Node40B790;
typedef struct { int key; Obj40B790* val; } Pair40B790;
typedef struct { void* it; unsigned char ok; } Res40B790;
extern void ObjRegistry_InsertOne(void* list, Obj40B790** o);
extern void ObjMap_Insert(Res40B790* out, void* map, Pair40B790* p);
#if 0 /* merge_units */
extern char D_00571C10[];
#endif /* merge_units */
#define D_00571C10 ((char*)&D_00571C10) /* merge_units */

#pragma push
#pragma opt_propagation off
unsigned char ObjRegistry_AppendRecursive(Node40B790* n, Obj40B790* o) {
    Res40B790 r;
Pair40B790 p;
    ObjRegistry_InsertOne(n->list, &o);
    if (n->parent) return ObjRegistry_AppendRecursive(n->parent, o);
    p.key = o->key;
    p.val = o;
    ObjMap_Insert(&r, D_00571C10, &p);
    return r.ok;
}
#pragma pop
#undef D_00571C10 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040B790 */
