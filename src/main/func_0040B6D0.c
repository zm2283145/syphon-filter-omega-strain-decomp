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
