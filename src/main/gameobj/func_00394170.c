/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern unsigned char func_003A2670(void* p);

/* Returns func_003A2670(self->unk64), or 0 when unk64 is null. */
int func_00394170(cVUM_GOBJ* self) {
    void* p = self->unk64;
    int result = 0;

    if (p != 0) {
        result = func_003A2670(p);
    }
    return result;
}
