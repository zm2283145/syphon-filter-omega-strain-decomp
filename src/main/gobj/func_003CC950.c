#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C003CC950 { public: VPAD16(p0) VPAD8(p1)  virtual int f(); };
struct O003CC950 { char pad[0x58]; C003CC950* m; };
extern "C" int Controller_NotifySeen(O003CC950* self)
{
    C003CC950* m = self->m;
    int r = -0x1;
    if (m)
        r = m->f();
    return r;
}
