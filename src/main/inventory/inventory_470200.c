/*
 * main/inventory: 2 files, 00470200-00470240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00470200 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptUtils_types.h"

extern void Global_cInventory__RegisterItem(int item, int count);

/* Script native: cInventory::RegisterItem(item, count). */
int Script_cInventory__RegisterItem(ScriptArg* args) {
    volatile int count = args[1].i;
    volatile int item = args[0].i;
    Global_cInventory__RegisterItem(item, count);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00470200 */

/* merge_units: begin func_00470240 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies just before inventory.cc (starts 0x004702A0); probably part of it.
 */

#include "loose05_types.h"

extern TextPairEntry* D_00587FF8; /* 44-byte entries */
extern int Loc_GetTextById(int id);

/* Localized text for the second id of entry `index`. */
int func_00470240(int index) {
    TextPairEntry* entry;

    entry = D_00587FF8 + index;
    return Loc_GetTextById(entry->textId1);
}

/* Localized text for the first id of entry `index`. */
int func_00470270(int index) {
    TextPairEntry* table;
    int id;

    table = D_00587FF8;
    id = table[index].textId0;
    return Loc_GetTextById(id);
}
#pragma pop /* merge_units */
/* merge_units: end func_00470240 */
