#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C003CDE00 { public: VPAD1(p0)  virtual void f(); };
struct O003CDE00 { char pad[0x50]; C003CDE00* m; };
extern "C" void func_003CDE00(O003CDE00* self)
{
    C003CDE00* m = self->m;
    if (m)
        m->f();
}
