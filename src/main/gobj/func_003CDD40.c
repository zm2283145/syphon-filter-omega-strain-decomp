#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C3CDD40 { public: VPAD4(a) virtual void f18(); };
struct O3CDD40 { char pad[0x50]; C3CDD40* m; };
extern "C" void func_003CDD40(O3CDD40* self)
{
    C3CDD40* m = self->m;
    if (m)
        m->f18();
}