/*
 * Matched functions (byte-identical with the retail executable).
 * Small constructors / forwarding helpers.
 */

#include "types.h"
#include "AgentData_types.h"

extern Rel* func_00336DC0(Rel* r);
extern int func_00337140(int a0, int a1, int a2);

int func_00336D80(int a0, int a1, int a2) {
    return func_00337140(a0, a1, a2);
}

/* Clears the three words and sets the flag. */
RelFlag* func_00336D90(RelFlag* self) {
    func_00336DC0(&self->rel);
    self->flag = 1;
    return self;
}
