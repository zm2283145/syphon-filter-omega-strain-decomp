/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern char D_004D9960[];  /* class table */
extern char D_004EE6C0[];
extern void cSystem_ctor(void* self, void* type);
extern void std_list_deleter_voidPtr_ctor_void(void* self);

HotboxReceiver* cHotboxMan_ctor(HotboxReceiver* self, int unk20) {
    cSystem_ctor(self, D_004EE6C0);
    self->vtable = D_004D9960;
    std_list_deleter_voidPtr_ctor_void(self->unk28);
    self->unk20 = unk20;
    self->unk24 = 0;
    return self;
}
