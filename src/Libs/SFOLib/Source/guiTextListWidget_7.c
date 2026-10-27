/*
 * Libs/SFOLib/Source/guiTextListWidget: 3 files, 00421F10-00421F30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00421F10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: guiTextListWidget.cc. Functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* std_vector_Item_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00421F10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421F10 */

/* merge_units: begin func_00421F30 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "direct_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(std_vector_imp_Item_dtor, std_vector_deleter_Item_dtor)
static inline void merge_flush_func_00421F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00421F30 */

/* merge_units: begin func_00421F90 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; } G4_E14;
typedef struct { int x; int size; G4_E14* data; } G4_Vec;
extern void String_Dtor(G4_E14* e, int f);
static inline void destroy_(G4_E14* p) { if (p) String_Dtor(p, 0); }
void std_vector_deleter_Item_clear(G4_Vec* v)
{
    G4_E14* b = v->data;
    G4_E14* e = b + v->size;
    while (b < e) {
        G4_E14* p = --e;
        if (p) destroy_(p);
    }
    v->size = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00421F90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00421F90 */
