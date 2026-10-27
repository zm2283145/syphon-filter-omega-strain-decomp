/*
 * Matched functions (byte-identical with the retail executable).
 * PathReceiver constructor.
 */

#include "types.h"
#include "path_types.h"

extern char D_004D96C0[]; /* PathReceiver vtable */
extern char g_NpcRouteMgr[]; /* receiver registration data */
extern void* cSystem_ctor(void* self, void* info);
extern PathList* std_list_deleter_voidPtr_ctor_void(PathList* list);

PathReceiver* cPathSystem_ctor(PathReceiver* self) {
    cSystem_ctor(self, g_NpcRouteMgr);
    self->vtable = D_004D96C0;
    std_list_deleter_voidPtr_ctor_void(&self->listA);
    std_list_deleter_voidPtr_ctor_void(&self->listB);
    return self;
}
