#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C003CDBE0 { public: VPAD4(p0) VPAD2(p1) VPAD1(p2)  virtual void f(); };
struct O003CDBE0 { char pad[0x50]; C003CDBE0* m; };
extern "C" void func_003CDBE0(O003CDBE0* self)
{
    C003CDBE0* m = self->m;
    if (m)
        m->f();
}
