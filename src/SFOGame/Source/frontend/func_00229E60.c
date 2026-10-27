/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DB810;
extern int std_list_deleter_cHogFile_ctor(int*);
extern int cSystemContainer_ctor_void(Unk229E60*);
extern int cMotionManager_InitStatics(void);

Unk229E60* cFrontendSystem_ctor(Unk229E60* self) {
    cSystemContainer_ctor_void(self);
    self->vtable = &D_004DB810;
    std_list_deleter_cHogFile_ctor(&self->unk2C);
    cMotionManager_InitStatics();
    return self;
}
