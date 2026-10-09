/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 * cVUM_GOBJ overrides that forward to cGOBJ and then to the model context.
 */

#include "gobj_types.h"

extern int func_0038E100(int* p);
extern void func_003A9F00(int* ctx);
extern int func_003A9F10(int* ctx);
extern void func_003CE790(cVUM_GOBJ* self);
extern void func_003CE7D0(cVUM_GOBJ* self);
extern void func_003CE810(cVUM_GOBJ* self);

void func_003928A0(cVUM_GOBJ* self) {
    func_003CE7D0(self);
    func_003A9F00(&self->modelCtx);
}

void func_003928D0(cVUM_GOBJ* self) {
    func_003CE790(self);
    func_003A9F00(&self->modelCtx);
}

void func_00392900(cVUM_GOBJ* self) {
    func_003A9F10(&self->modelCtx);
    self->model = &self->modelCtx;
    func_0038E100(&self->unk60);
    func_003CE810(self);
}
