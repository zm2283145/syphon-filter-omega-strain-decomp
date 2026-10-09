/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern char D_004D99A0[];  /* trigger-zone class table (handler TriggerZone_HandleEvent) */
extern void cHotbox_ctor(cHotbox* self, int a1, int a2);

/* Trigger-zone constructor: a cHotbox with its own class table. */
cHotbox* TriggerZone_ctor(cHotbox* self, int a1) {
    cHotbox_ctor(self, a1, 12);
    self->vtable = D_004D99A0;
    return self;
}
