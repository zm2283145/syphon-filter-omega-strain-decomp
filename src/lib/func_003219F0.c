#include "types.h"
typedef struct { int w0, w4, w8, wC, w10, w14, w18; char pad1C[0x14]; float rate; float pos; char pad38[0xC]; short hold; short pad46; int buf[1]; } V3219F0;
extern void func_00321D18(float x, float y, float r, int a, int b, int c, int d, int e, int f, int g, int* buf, int h, int i);
void func_003219F0(V3219F0* s, float (*tbl)[2], int arg, int* cnt, int e5, int e6)
{
    float step = s->rate * 160.0f;
    if (s->pos <= step) {
        float r = s->pos / step;
        float* p;
        if (r < 0.75f) p = tbl[0]; else p = tbl[1];
        func_00321D18(p[0], p[1], r, s->w0, arg, s->w4, s->wC, s->w10, s->w14, s->w18, s->buf, e5, e6);
        s->pos += 80.0f;
        *cnt += 80;
    }
    if (s->hold == 0 && s->pos > step) s->pos -= step;
}