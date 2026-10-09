/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern char D_004D9960[];  /* class table */
extern char D_004EE6C0[];
extern void Receiver_Construct(void* self, void* type);
extern void ScalarCollection_Init(void* self);

HotboxReceiver* func_001716E0(HotboxReceiver* self, int unk20) {
    Receiver_Construct(self, D_004EE6C0);
    self->vtable = D_004D9960;
    ScalarCollection_Init(self->unk28);
    self->unk20 = unk20;
    self->unk24 = 0;
    return self;
}
