/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern unsigned char cParticle_EventHappened(void* p);

/* Returns cParticle_EventHappened(self->unk64), or 0 when unk64 is null. */
int cPARTICLE_GOBJ_EventHappened(cVUM_GOBJ* self) {
    void* p = self->unk64;
    int result = 0;

    if (p != 0) {
        result = cParticle_EventHappened(p);
    }
    return result;
}
