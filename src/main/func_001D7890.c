#include "types.h"
typedef struct { int pad0; union { unsigned int u; int i; } frames; int pad8; float fps; } C1D7890;
typedef struct { C1D7890* clip; int owner; float rate; int w0C, w10, w14, w18, w1C; unsigned char b20; } K1D7890;
extern void Clip_AdvanceCursor(K1D7890* k, float t);
K1D7890* func_001D7890(K1D7890* k, C1D7890* clip, int owner)
{
    k->clip = clip;
    k->owner = owner;
    k->rate = 0;
    k->w0C = 0;
    k->w10 = 0;
    k->w14 = 0;
    k->w18 = 0;
    k->w1C = 0;
    k->b20 = 0;
    {
        C1D7890* c = k->clip;
        k->rate = (float)c->frames.i / ((float)c->frames.u * c->fps);
    }
    Clip_AdvanceCursor(k, 0.0f);
    return k;
}