#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Obj002240E0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void on(int arg);
    virtual void off(int arg);
    char pad[0x2A];
    char b2E;
};
extern "C" void ZoneMgr_OnAsyncLoaded(void* unused, Obj002240E0* o, int enable)
{
    if (enable) {
        o->on(0);
        o->b2E = 0;
    } else {
        o->off(0);
    }
}