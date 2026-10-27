/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc: localized text lookup.
 */

#include "types.h"

extern int GetIndexFromLabel(int key);
extern int nGlobalization_GetString_int(int id);

int nGlobalization_GetStringIndex(int key) {
    return GetIndexFromLabel(key);
}

/* Resolve a key to a string id, then to its text. */
int nGlobalization_GetString_charP(int key) {
    return nGlobalization_GetString_int(GetIndexFromLabel(key));
}
