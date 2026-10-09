/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern Rel* func_00393CC0(Rel* r);

void* func_00393C50(char* self) {
    return self + 4;
}

void func_00393C60(int* self, int value) {
    *self = value;
}

Rel* func_00393C70(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

RelFlag* func_00393C90(RelFlag* r) {
    func_00393CC0(&r->rel);
    r->flag = 1;
    return r;
}
