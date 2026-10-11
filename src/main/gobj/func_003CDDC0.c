#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C003CDDC0 { public: VPAD2(p0)  virtual void f(); };
struct O003CDDC0 { char pad[0x50]; C003CDDC0* m; };
extern "C" void func_003CDDC0(O003CDDC0* self)
{
    C003CDDC0* m = self->m;
    if (m)
        m->f();
}
