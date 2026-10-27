/*
 * SFOGame/Source/humanAnimData: 3 files, 001F04E0-001F05D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001F04E0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_001F04E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F04E0 */

/* merge_units: begin func_001F0540 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

#if 0 /* merge_units */
extern void* D_004DFC10;
#endif /* merge_units */
#define D_004DFC10 (*(void **)&D_004DFC10) /* merge_units */

extern Vec4* cVector_ctor_cVectorR(Vec4*, Vec4*);
extern int cSkaAnim_ctor_eType_cSkaAnimR_eAxisOfMotion_bool(Unk1F0540*, int, int, int, int);

Unk1F0540* cSkaRotatableAnim_ctor(Unk1F0540* self, int a1, int a2, Vec4* a3, int t0, float f12, float f13) {
    cSkaAnim_ctor_eType_cSkaAnimR_eAxisOfMotion_bool(self, 1, a2, 0, t0);
    self->vtable = &D_004DFC10;
    self->unk50 = a1;
    self->unk54 = f12;
    self->unk58 = f13;
    cVector_ctor_cVectorR(&self->unk60, a3);
    return self;
}
#undef D_004DFC10 /* merge_units */
static inline void merge_flush_func_001F0540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F0540 */

/* merge_units: begin func_001F05D0 */
#pragma push /* merge_units */
/* Converts degrees to radians. */
float Deg2Rad(float deg)
{
    return 0.017453292f * deg;
}
static inline void merge_flush_func_001F05D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001F05D0 */
