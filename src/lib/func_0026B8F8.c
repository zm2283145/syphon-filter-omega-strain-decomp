#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { char pad[0x7C]; int priority; } Item;
typedef struct { char pad[0x10]; Item* items; char pad14[0x334 - 0x14]; } Slot;
extern Slot D_004FBB88[];
extern void func_0010DA58(Item* a, Item* b);

/* Processes the slot's item block and returns whichever of its first two items has higher priority. */
Item* func_0026B8F8(int idx)
{
    Item* pair[2];
    Item* base = D_004FBB88[idx].items;
    pair[1] = (Item*)((char*)base + 0x80);
    pair[0] = base;
    func_0010DA58(base, (Item*)((char*)base + 0x100));
    return pair[pair[0]->priority < pair[1]->priority];
}
