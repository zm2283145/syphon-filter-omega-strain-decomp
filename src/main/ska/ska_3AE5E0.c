/*
 * main/ska: range (2 files, 003AE5E0-003AE690)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003AE5E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
struct C6Ent_3AE5E0 { int key; int pad[3]; char value[0x170]; };
struct C6Coll_3AE5E0 { int pad0; int count; };
extern "C" C6Ent_3AE5E0** std_vector_deleter_cSkaAnimAnchorListEntry_data(C6Coll_3AE5E0*);
extern "C" char D_005429F0[];
static inline int C6Eq(C6Ent_3AE5E0* a, C6Ent_3AE5E0* b) { return a == b; }
extern "C" void* RootCollection_FindByKey(C6Coll_3AE5E0* self, int* key) {
    C6Ent_3AE5E0* it = *std_vector_deleter_cSkaAnimAnchorListEntry_data(self);
    C6Ent_3AE5E0* end = *std_vector_deleter_cSkaAnimAnchorListEntry_data(self) + self->count;
    for (; C6Eq(it, end) ^ 1; it++) {
        if (it->key == *key) return it->value;
    }
    return D_005429F0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AE5E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AE5E0 */

/* merge_units: begin func_003AE690 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off

extern "C" C6Ent_3AE5E0** func_003AE740(C6Coll_3AE5E0*);
extern "C" void* Secondary_RootWeight(C6Coll_3AE5E0* self, int* key) {
    C6Ent_3AE5E0* it = *func_003AE740(self);
    C6Ent_3AE5E0* end = *func_003AE740(self) + self->count;
    for (; C6Eq(it, end) ^ 1; it++) {
        if (it->key == *key) return it->value;
    }
    return D_005429F0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AE690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AE690 */
