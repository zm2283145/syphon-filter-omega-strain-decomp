/*
 * lib/libdbc: 2 files, 0026B890-0026B8F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026B890 */
#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { char pad[0x7C]; int priority; } Item;
typedef struct { char pad[0x10]; Item* items; char pad14[0x334 - 0x14]; } Slot;
extern Slot D_004FBB88[];
extern void SyncDCache(Item* a, Item* b);

/* Processes the slot's item block and returns whichever of its first two items has higher priority. */
Item* scePad2GetSide(int idx)
{
    Item* pair[2];
    Item* base = D_004FBB88[idx].items;
    pair[1] = (Item*)((char*)base + 0x80);
    pair[0] = base;
    SyncDCache(base, (Item*)((char*)base + 0xFF));
    return pair[pair[0]->priority < pair[1]->priority];
}
/* merge_units: end func_0026B890 */

/* merge_units: begin func_0026B8F8 */
/* Processes the slot's item block and returns whichever of its first two items has higher priority. */
Item* scePad2GetSide2(int idx)
{
    Item* pair[2];
    Item* base = D_004FBB88[idx].items;
    pair[1] = (Item*)((char*)base + 0x80);
    pair[0] = base;
    SyncDCache(base, (Item*)((char*)base + 0x100));
    return pair[pair[0]->priority < pair[1]->priority];
}
/* merge_units: end func_0026B8F8 */
