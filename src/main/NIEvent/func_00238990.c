#include "types.h"
#pragma cplusplus on
#pragma opt_strength_reduction off
class A1_Item {
public:
    virtual void Fire(int arg);
    float t;
};
struct A1_Obj { int a0; unsigned char active; float time; int pad; int count; A1_Item** items; };
extern "C" bool func_00238990(A1_Obj* o, float dt) {
    bool ret = false;
    float t = o->time + dt;
    int i;
    if (o->active) {
        for (i = 0; i < o->count; i++) {
            A1_Item* it = o->items[i];
            if (it->t <= t && !(it->t <= o->time)) {
                it->Fire(o->a0);
                ret = true;
            }
        }
        o->time = t;
    }
    return ret;
}