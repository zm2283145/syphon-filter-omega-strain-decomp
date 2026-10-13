#pragma cplusplus on
#include "types.h"
struct TgtA20 { char pad[0x14]; float x; float y; };
struct EntA20 { TgtA20* p; float x; float y; };
struct OwnA20 { char pad[0x144]; float t; };
struct SelfA20 { void* obj; OwnA20* own; EntA20 e[2]; int n; float last; unsigned char on; };
extern float D_0048B3D0;
extern "C" unsigned char func_00287AB0(SelfA20*);
extern "C" void func_00287A20(SelfA20* s)
{
    int i;
    if (func_00287AB0(s)) {
        float d;
        float t;
        t = s->own->t;
        d = t - s->last;
        s->last = t;
        d = d * D_0048B3D0;
        for (i = 0; i < s->n; i++) {
            TgtA20* p = s->e[i].p;
            float a = d * s->e[i].x;
            float b = d * s->e[i].y;
            p->x = a;
            p->y = b;
        }
    }
}

