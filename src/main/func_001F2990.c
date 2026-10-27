#pragma cplusplus on
#include "types.h"
extern "C" {
extern "C" void cSkaSwitch_UpdateNodes();
extern "C" void cSkaNode_PlaybackGroupId();
extern void * const D_004DFBB0[];
void* cArray_cSkaSwitchItem_dtor(void* self, short deleteFlag);
void* cSkaNode_dtor(void* self, short deleteFlag);
void operator_delete(void* allocation);
}
struct O1F2990 { void* vtable; char pad[0x20]; char member[4]; };
extern "C" O1F2990* cSkaSwitch_dtor(O1F2990* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DFBB0);
        cArray_cSkaSwitchItem_dtor(self->member, -1);
        cSkaNode_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DFBB0[8] = { (void*)0x0, (void*)0x0, (void*)cSkaSwitch_dtor, (void*)cSkaSwitch_UpdateNodes, (void*)cSkaNode_PlaybackGroupId, (void*)0x0, (void*)0x0, (void*)0x0 };
