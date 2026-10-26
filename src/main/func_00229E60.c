/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DB810;
extern int std_list_deleter_cHogFile_ctor(int*);
extern int ListReceiver_Ctor(Unk229E60*);
extern int MotionManager_Init(void);

Unk229E60* FrontEndScene_ctor(Unk229E60* self) {
    ListReceiver_Ctor(self);
    self->vtable = &D_004DB810;
    std_list_deleter_cHogFile_ctor(&self->unk2C);
    MotionManager_Init();
    return self;
}
