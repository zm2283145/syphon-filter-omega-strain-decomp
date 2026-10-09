/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern FlaggedRel D_00532A70[5];
/* Runtime array constructor without destructor: (array, ctor, element size, count). */
extern void func_00100440(void* array, void* ctor, int size, int count);
extern int func_0033C280(FlaggedRel*);
extern int func_0033C2A0(int, int);

Rel* func_0033C120(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Static initializer: construct the five entries of D_00532A70. */
void func_0033C140(void) {
    func_00100440(D_00532A70, func_0033C2A0, 16, 5);
}

FlaggedRel* func_0033C160(FlaggedRel* self) {
    func_0033C280(self);
    self->unk0C = 1;
    return self;
}
