/*
 * SFOGame/Source/frontend: 1 file, 00229E60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00229E60 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_00229E60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00229E60 */
