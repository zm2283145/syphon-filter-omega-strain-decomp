#pragma cplusplus on
#include "types.h"
class Obj00236EA0 {
public:
    int id;
    virtual void s0();
    virtual void s1();
    virtual void release();
};
struct Raw00236EA0 { int id; void* vt; };
extern "C" char D_004DBE90[];
extern "C" char D_004D9280[];
extern "C" void func_003EC950(void* p);
extern "C" Obj00236EA0* func_00236EA0(Obj00236EA0* self, short deleteFlag)
{
    if (self) {
        Raw00236EA0* r = (Raw00236EA0*)self;
        r->vt = D_004DBE90;
        self->release();
        if (self)
            r->vt = D_004D9280;
        if (deleteFlag > 0)
            func_003EC950(self);
    }
    return self;
}
