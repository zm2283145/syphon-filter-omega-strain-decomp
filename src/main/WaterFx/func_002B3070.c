#include "types.h"
typedef struct {
    char pad0[0x300];
    float sinTab[64];
    void* slots[20];
    int a450;
    int a454;
} C3WaterFx;
extern void WaterFx_BuildGrid(C3WaterFx* w);
extern float Math_Sin(float x);
C3WaterFx* WaterFx_Construct(C3WaterFx* w)
{
    int i;
    int j;
    float a;
    w->a450 = 0;
    w->a454 = 0;
    for (i = 0; i < 20; i++) {
        w->slots[i] = 0;
    }
    WaterFx_BuildGrid(w);
    a = -3.1415927f;
    for (j = 0; j < 64; j++) {
        w->sinTab[j] = Math_Sin(a);
        a += 0.09817477f;
    }
    return w;
}