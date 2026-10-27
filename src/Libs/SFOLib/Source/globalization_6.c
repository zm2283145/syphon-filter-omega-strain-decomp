/*
 * Libs/SFOLib/Source/globalization: 1 file, 003FE090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FE090 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc: current language selection.
 */

#include "types.h"
#include "globalization_types.h"

/* Language names, indexed by language id. */
extern char D_004BE3C0[];
extern char D_004BE3C8[];
extern char D_004BE3D0[];
extern char D_004BE3D8[];
extern char D_004BE3E0[];
extern char D_004BE3E8[];
extern char D_004BE3F0[];
static void * const dat_00493A20[8] = { (void*)D_004BE3C0, (void*)D_004BE3C8, (void*)D_004BE3D0, (void*)D_004BE3D8, (void*)D_004BE3E0, (void*)D_004BE3E8, (void*)D_004BE3F0, (void*)0x0 };
/* STRINGS<suffix>.DAT file suffixes, indexed by language id (index 0 is ""). */
extern char* D_00493A40[LANGUAGE_COUNT + 1];
/* Current language id. */
extern signed char D_0055D470;

/* File suffix of the current language. */
char* Loc_GetLanguageSuffix(void) {
    return D_00493A40[(unsigned char)D_0055D470];
}

/* Name of language `id`. */
char* nGlobalization_GetLanguageName_eLanguage(int id) {
    return ((char**)dat_00493A20)[id & 255];
}

/* Name of the current language. */
char* nGlobalization_GetLanguageName_void(void) {
    return ((char**)dat_00493A20)[(unsigned char)D_0055D470];
}

/* Current language id. */
int Loc_GetLanguage(void) {
    return D_0055D470;
}

/* Select the current language. */
void Loc_SetLanguage(int id) {
    D_0055D470 = id;
}
static inline void merge_flush_func_003FE090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FE090 */
