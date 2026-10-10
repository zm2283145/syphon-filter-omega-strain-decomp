#include "GobjMan_types.h"

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
