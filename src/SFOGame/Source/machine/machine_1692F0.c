/*
 * main/machine: range (2 files, 001692F0-00169330)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001692F0 */
#pragma push /* merge_units */
extern char D_005721F0;   /* already-initialized flag / instance */
extern char D_005721E0[];
extern void* nGlobalization_GetString_charP(void* storage);

/* Lazy singleton: returns the instance if set up, else initializes it. */
void* cDME_GetQuitMessage(void) {
    if (D_005721F0) {
        return &D_005721F0;
    }
    return nGlobalization_GetString_charP(D_005721E0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001692F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001692F0 */

/* merge_units: begin func_00169330 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern signed char D_005721F0;
#endif /* merge_units */
#define D_005721F0 (*(signed char*)&D_005721F0) /* merge_units */

#if 0 /* merge_units */
extern int D_005721E0;
#endif /* merge_units */
#define D_005721E0 (*(int*)&D_005721E0) /* merge_units */

#if 0 /* merge_units */
extern int nGlobalization_GetString_charP(void*);
#endif /* merge_units */
#define nGlobalization_GetString_charP(a0) ((int)nGlobalization_GetString_charP((a0))) /* merge_units */


/* Returns nGlobalization_GetString_charP(&D_005721E0) when the D_005721F0 flag is set, else 0. */
int cDME_GetQuitTitle(void) {
    int r = D_005721F0;
    if (r != 0) r = nGlobalization_GetString_charP(&D_005721E0);
    else r = 0;
    return r;
}
#undef D_005721F0 /* merge_units */
#undef D_005721E0 /* merge_units */
#undef nGlobalization_GetString_charP /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169330 */
