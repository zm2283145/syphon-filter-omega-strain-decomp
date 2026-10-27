#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct R_C1E0 { int a; int b; int c; int d; R_C1E0() {} };
class O_C1E0 {
public:
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual R_C1E0 Get(int i);
    char pad[0x40];
    int mode;
};
struct G_C1E0 { char pad[0x3470]; unsigned char net; };
struct H_C1E0 { char pad[0x30]; G_C1E0* g; };
struct S_C1E0 { char pad[0x3C]; H_C1E0* h; };
extern "C" void cAITarget_TestPointInViewCone(S_C1E0* self, R_C1E0* r, int x, int mode);
extern "C" void cAITarget_TestGobjInViewCone(S_C1E0* self, O_C1E0* o, int x)
{
    R_C1E0 r = o->Get(-1);
    int mode = o->mode;
    if (self->h->g->net == 1)
        mode = 0;
    cAITarget_TestPointInViewCone(self, &r, x, mode);
}