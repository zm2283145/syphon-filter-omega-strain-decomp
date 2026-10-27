#pragma cplusplus on
#include "types.h"
#include "vtable_base_dtor.h"
extern "C" {
extern "C" void cSkaAnim_PlaybackGroupId();
extern "C" void cSkaRotatableAnim_UpdateNodes();
extern void * const D_004DFC10[];
void* cSkaAnim_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cSkaRotatableAnim_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFC10);
        cSkaAnim_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFC10[8] = { (void*)0x0, (void*)0x0, (void*)cSkaRotatableAnim_dtor, (void*)cSkaRotatableAnim_UpdateNodes, (void*)cSkaAnim_PlaybackGroupId, (void*)0x0, (void*)0x0, (void*)0x0 };
