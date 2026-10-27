/*
 * SFOGame/Source/humanAnimData: 1 file, 001F3710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F3710 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int std_list_imp_voidPtr_size(void);
extern ObjVec* std_vector_cSkaTransBLEND_ctor_void(ObjVec*);
extern ObjVec* std_vector_imp_cSkaTransBLEND_ctor_void(ObjVec*);
extern ObjVec* std_vector_deleter_cSkaTransBLEND_ctor_void(ObjVec*);
extern int std_vector_imp_cSkaTransBLEND_reserve(int, int);

int std_vector_cSkaTransBLEND_reserve(int a0, int a1) {
    return std_vector_imp_cSkaTransBLEND_reserve(a0, a1);
}

int cLList_cSkaTransBLENDPtr_Size(void) {
    return std_list_imp_voidPtr_size();
}

/* Array constructor: sets the owns-storage flag. */
ObjVec* cArray_cSkaTransBLEND_ctor_void(ObjVec* self) {
    std_vector_cSkaTransBLEND_ctor_void(self);
    self->owned = 1;
    return self;
}

ObjVec* std_vector_cSkaTransBLEND_ctor_void(ObjVec* self) {
    std_vector_imp_cSkaTransBLEND_ctor_void(self);
    return self;
}

ObjVec* std_vector_imp_cSkaTransBLEND_ctor_void(ObjVec* self) {
    std_vector_deleter_cSkaTransBLEND_ctor_void(self);
    return self;
}
static inline void merge_flush_func_001F3710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F3710 */
