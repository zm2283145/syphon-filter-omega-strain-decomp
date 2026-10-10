#include "types.h"
#pragma cplusplus on
struct P397AB0 { char pad[0x8F4]; int f8F4; };
class O397AB0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual P397AB0* get();
    char pad[0x5C];
    float f60;
    float f64;
};
extern "C" bool func_00397AB0(O397AB0* o, float x) {
    return !o->get()->f8F4 && (x - o->f64 > o->f60);
}