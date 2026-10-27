/*
 * main/guiTextListWidget: range (2 files, 00421F30-00421F90)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "direct_base_dtor.h"
#pragma pop

/* merge_units: begin func_00421F30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(std_vector_imp_Item_dtor, std_vector_deleter_Item_dtor)
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
