/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver constructor.
 */

#include "types.h"
#include "path_types.h"

extern char D_004D96C0[]; /* PathReceiver vtable */
extern char D_004ED9B0[]; /* receiver registration data */
extern void* Receiver_Construct(void* self, void* info);
extern PathList* ScalarCollection_Init(PathList* list);

PathReceiver* func_00164620(PathReceiver* self) {
    Receiver_Construct(self, D_004ED9B0);
    self->vtable = D_004D96C0;
    ScalarCollection_Init(&self->listA);
    ScalarCollection_Init(&self->listB);
    return self;
}
