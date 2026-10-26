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
extern int Vector_Reserve_20B3F0(int, int);

int Vector_Reserve_20B3F0_Thunk_1F3710(int a0, int a1) {
    return Vector_Reserve_20B3F0(a0, a1);
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
