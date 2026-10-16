#include "types.h"
#pragma cplusplus on
class E3EE740 {
public:
    virtual void v0();
    virtual float get();
};
struct O3EE740 {
    char pad0[0x6C];
    unsigned short n6C;
    unsigned short n6E;
    char pad70[0x10];
    E3EE740** items;
    O3EE740** kids;
};
extern "C" float func_003EE740(O3EE740* o) {
    int i;
    int j;
    float m = 0.0f;
    for (i = 0; i < o->n6C; i++) {
        float v = o->items[i]->get();
        if (v > m) m = v;
    }
    for (j = 0; j < o->n6E; j++) {
        float v = func_003EE740(o->kids[j]);
        if (v > m) m = v;
    }
    return m;
}