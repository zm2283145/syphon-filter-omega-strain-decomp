#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C3CE810 { public: VPAD16(a) virtual void f(); };
struct O3CE810 { char pad[0x2D]; unsigned char b2D; char pad2[0x2A]; C3CE810* m; };
extern "C" void func_003CE810(O3CE810* self)
{
    self->b2D = 1;
    C3CE810* m = self->m;
    if (m)
        m->f();
}