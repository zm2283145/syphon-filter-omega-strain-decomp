/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ overrides that forward to cGOBJ and then to the model context.
 */

#include "gobj_types.h"

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
