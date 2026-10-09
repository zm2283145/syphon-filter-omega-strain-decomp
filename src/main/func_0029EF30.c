/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void* func_00414790(void);
extern int func_00418E00(void* mgr, int resource, int arg);
extern int func_0041F090(GuiWidget* self);

/* GuiOnlineConnect vtable slot 2: base call, then release the held resource. */
void func_0029EF30(GuiOnlineConnect* self) {
    int resource;

    func_0041F090(&self->base.base.base);
    resource = self->resource;
    if (resource != 0) {
        func_00418E00(func_00414790(), resource, 0);
        self->resource = 0;
    }
}
