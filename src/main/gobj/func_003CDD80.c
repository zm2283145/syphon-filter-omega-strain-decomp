#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C003CDD80 { public: VPAD2(p0) VPAD1(p1)  virtual void f(); };
struct O003CDD80 { char pad[0x50]; C003CDD80* m; };
extern "C" void func_003CDD80(O003CDD80* self)
{
    C003CDD80* m = self->m;
    if (m)
        m->f();
}
