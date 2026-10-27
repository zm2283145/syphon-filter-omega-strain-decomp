/*
 * main/gameobj: range (2 files, 003928A0-00392940)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"
#include "types.h"

/* merge_units: begin func_003928A0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ overrides that forward to cGOBJ and then to the model context.
 */


extern int cMan_SetGunOffsets(int* p);
extern void cSkeleton_Deactivate(int* ctx);
extern int cSkeleton_Activate(int* ctx);
extern void cGOBJ_Deactivate(cVUM_GOBJ* self);
extern void cGOBJ_NetDeactivate(cVUM_GOBJ* self);
extern void cGOBJ_NetActivate(cVUM_GOBJ* self);

void cSKM_GOBJ_NetDeactivate(cVUM_GOBJ* self) {
    cGOBJ_NetDeactivate(self);
    cSkeleton_Deactivate(&self->modelCtx);
}

void cSKM_GOBJ_Deactivate(cVUM_GOBJ* self) {
    cGOBJ_Deactivate(self);
    cSkeleton_Deactivate(&self->modelCtx);
}

void cSKM_GOBJ_NetActivate(cVUM_GOBJ* self) {
    cSkeleton_Activate(&self->modelCtx);
    self->model = &self->modelCtx;
    cMan_SetGunOffsets(&self->unk60);
    cGOBJ_NetActivate(self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003928A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003928A0 */

/* merge_units: begin func_00392940 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma opt_common_subs off

typedef struct Obj3929 {
    char pad0000[0x60];
    char part60[0x2C04];    /* 0x0060 */
    void* current;          /* 0x2C64 */
    char pad2C68[0x1E8];
    char part2E50[4];       /* 0x2E50 */
} Obj3929;

#if 0 /* merge_units */
extern int cSkeleton_Activate(void* part);
#endif /* merge_units */
#define cSkeleton_Activate(a0) (cSkeleton_Activate((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int cMan_SetGunOffsets(void* part);
#endif /* merge_units */
#define cMan_SetGunOffsets(a0) (cMan_SetGunOffsets((void *)(a0))) /* merge_units */

extern void cGOBJ_Activate(Obj3929* self, int arg);

/* Initializes the sub-parts and activates the object. */
void cSKM_GOBJ_Activate(Obj3929* self, int arg) {
    cSkeleton_Activate(self->part2E50);
    self->current = self->part2E50;
    cMan_SetGunOffsets(self->part60);
    cGOBJ_Activate(self, arg);
}

#pragma pop
#undef cSkeleton_Activate /* merge_units */
#undef cMan_SetGunOffsets /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00392940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00392940 */
