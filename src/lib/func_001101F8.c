#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct Item { int key; char pad[0x34]; struct Item* next; } Item;
typedef struct Group { char pad[8]; Item* items; char padC[8]; struct Group* next; } Group;
typedef struct { char pad[0x28]; Group* groups; } Owner;

/* Searches all groups of owner for the item with the given key. */
Item* func_001101F8(int key, Owner* owner)
{
    Group* g;
    Item* it;
    for (g = owner->groups; g != 0; g = g->next) {
        for (it = g->items; it != 0; it = it->next) {
            if (it->key == key)
                return it;
        }
    }
    return 0;
}
