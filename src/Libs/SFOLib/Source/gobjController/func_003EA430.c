#pragma cplusplus on
#pragma bool off
#include "types.h"
#define V8A430(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); \
    virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
class OA430 {
public:
    V8A430(a) V8A430(b) V8A430(c) V8A430(d) V8A430(e) V8A430(f) V8A430(g) V8A430(h)
    virtual unsigned char getState();
};
static inline unsigned char busyA430(unsigned char s)
{
    unsigned char r = 1;
    if (!(s == 2 || s == 3))
        r = 0;
    return r;
}
struct TA430 { char pad[0x30]; OA430* obj; };
extern "C" unsigned char cGobjController_WantsToBeActive(TA430* self)
{
    OA430* o = self->obj;
    unsigned char r;
    if (!o) r = 1;
    else r = !busyA430(o->getState());
    return r;
}
