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


extern int Model_HardMeshAttachPoints(int* p);
extern void func_003A9F00(int* ctx);
extern int SkelNodes_ConstructActive(int* ctx);
extern void Object_Deactivate(cVUM_GOBJ* self);
extern void func_003CE7D0(cVUM_GOBJ* self);
extern void func_003CE810(cVUM_GOBJ* self);

void func_003928A0(cVUM_GOBJ* self) {
    func_003CE7D0(self);
    func_003A9F00(&self->modelCtx);
}

void func_003928D0(cVUM_GOBJ* self) {
    Object_Deactivate(self);
    func_003A9F00(&self->modelCtx);
}

void func_00392900(cVUM_GOBJ* self) {
    SkelNodes_ConstructActive(&self->modelCtx);
    self->model = &self->modelCtx;
    Model_HardMeshAttachPoints(&self->unk60);
    func_003CE810(self);
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
extern int SkelNodes_ConstructActive(void* part);
#endif /* merge_units */
#define SkelNodes_ConstructActive(a0) (SkelNodes_ConstructActive((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int Model_HardMeshAttachPoints(void* part);
#endif /* merge_units */
#define Model_HardMeshAttachPoints(a0) (Model_HardMeshAttachPoints((void *)(a0))) /* merge_units */

extern void Object_Activate(Obj3929* self, int arg);

/* Initializes the sub-parts and activates the object. */
void ActorModel_Activate(Obj3929* self, int arg) {
    SkelNodes_ConstructActive(self->part2E50);
    self->current = self->part2E50;
    Model_HardMeshAttachPoints(self->part60);
    Object_Activate(self, arg);
}

#pragma pop
#undef SkelNodes_ConstructActive /* merge_units */
#undef Model_HardMeshAttachPoints /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00392940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00392940 */
