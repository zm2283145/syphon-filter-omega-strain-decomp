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
