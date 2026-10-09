/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc: current language selection.
 */

#include "types.h"
#include "globalization_types.h"

/* Language names, indexed by language id. */
extern char* D_00493A20[LANGUAGE_COUNT + 1];
/* STRINGS<suffix>.DAT file suffixes, indexed by language id (index 0 is ""). */
extern char* D_00493A40[LANGUAGE_COUNT + 1];
/* Current language id. */
extern signed char D_0055D470;

/* File suffix of the current language. */
char* Loc_GetLanguageSuffix(void) {
    return D_00493A40[(unsigned char)D_0055D470];
}

/* Name of language `id`. */
char* Loc_GetLanguageName(int id) {
    return D_00493A20[id & 255];
}

/* Name of the current language. */
char* Loc_GetCurrentLanguageName(void) {
    return D_00493A20[(unsigned char)D_0055D470];
}

/* Current language id. */
int Loc_GetLanguage(void) {
    return D_0055D470;
}

/* Select the current language. */
void Loc_SetLanguage(int id) {
    D_0055D470 = id;
}
