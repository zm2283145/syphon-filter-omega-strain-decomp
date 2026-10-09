/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern Rel* func_00393FD0(Rel* r);
extern int func_00395EB0(Rel* r, int a1, int a2);

/* Clears the record, then calls func_00395EB0 with the incoming a1/a2 unchanged. */
Rel* func_00393F60(Rel* r, int a1, int a2) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    func_00395EB0(r, a1, a2);
    return r;
}

RelFlag* func_00393FA0(RelFlag* r) {
    func_00393FD0(&r->rel);
    r->flag = 1;
    return r;
}
