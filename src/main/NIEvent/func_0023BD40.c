#include "types.h"
#pragma cplusplus on
#pragma opt_strength_reduction off
#pragma exceptions off
class G7V { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void fn(int x); };
struct G7Ev { char pad[0x2C]; unsigned char b2C; char pad2[0xA0 - 0x2D]; int count; G7V** arr; };
extern "C" void cNIEventOBJ_v08(G7Ev* e)
{
    int i;
    e->b2C = 1;
    for (i = 0; i < e->count; i++) {
        e->arr[i]->fn(-1);
    }
}