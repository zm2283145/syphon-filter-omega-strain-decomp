#include "types.h"
typedef struct { int t; float v; } KtKey;
float KeyTrack_Sample(int t, KtKey* keys)
{
    int i = 0;
    int kt;
    float a, b;
    while (t > (kt = keys[i].t)) i++;
    if (t == kt) return keys[i].v;
    b = keys[i].v;
    a = keys[i - 1].v;
    if (a == b) return b;
    {
        int pt = keys[i - 1].t;
        int span = kt - pt;
        float r;
        t -= pt;
        r = (float)t / (float)span;
        return a - r * (a - b);
    }
}
