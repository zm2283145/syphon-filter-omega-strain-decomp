/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc: localized text lookup.
 */

#include "types.h"

extern int Loc_FindKey(int key);
extern int Loc_GetTextById(int id);

int Loc_FindKeyThunk(int key) {
    return Loc_FindKey(key);
}

/* Resolve a key to a string id, then to its text. */
int Loc_LookupText(int key) {
    return Loc_GetTextById(Loc_FindKey(key));
}
