/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern FlaggedRel D_00532A70[5];
/* Runtime array constructor without destructor: (array, ctor, element size, count). */
extern void __destroy_array(void* array, void* ctor, int size, int count);
extern int std_vector_imp_Record_ctor(FlaggedRel*);
extern int cArray_Record_dtor(int, int);

Rel* std_vector_RatingRecord_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Static initializer: construct the five entries of D_00532A70. */
void func_0033C140(void) {
    __destroy_array(D_00532A70, cArray_Record_dtor, 16, 5);
}

FlaggedRel* cArray_Record_ctor(FlaggedRel* self) {
    std_vector_imp_Record_ctor(self);
    self->unk0C = 1;
    return self;
}
