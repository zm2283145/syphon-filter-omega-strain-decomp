#pragma cplusplus on
#include "types.h"
struct B7_Ramp {
    virtual void v0(); virtual void v1();
    virtual void SetValue(float v); /* +0x10 */
    float value;
    float min;
    float max;
    float vel;
    unsigned char pingpong;
};
extern "C" void func_003F43D0(B7_Ramp* r, float dt)
{
    if (r->vel != 0.0f) {
        r->value += r->vel * dt;
        if (r->vel > 0.0f) {
            if (r->value > r->max) {
                if (r->pingpong) {
                    r->vel = -r->vel;
                    r->value = r->max;
                } else if (r->min == r->max) {
                    r->vel = 0.0f;
                    r->value = r->max;
                } else {
                    r->value = r->min;
                }
            }
        } else {
            if (r->value < r->min) {
                if (r->pingpong) {
                    r->vel = -r->vel;
                    r->value = r->min;
                } else if (r->min == r->max) {
                    r->vel = 0.0f;
                    r->value = r->min;
                } else {
                    r->value = r->max;
                }
            }
        }
        r->SetValue(r->value);
    }
}