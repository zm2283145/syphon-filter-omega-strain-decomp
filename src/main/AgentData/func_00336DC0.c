/*
 * Matched functions (byte-identical with the retail executable).
 * Small constructors / forwarding helpers.
 */

#include "types.h"
#include "AgentData_types.h"

extern int func_001396D0(int, int);
extern Rel* func_00336E40(Rel* r);

Rel* func_00336DC0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00336DE0(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_00336DF0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Clears the three words and sets the flag. */
RelFlag* func_00336E10(RelFlag* self) {
    func_00336E40(&self->rel);
    self->flag = 1;
    return self;
}
