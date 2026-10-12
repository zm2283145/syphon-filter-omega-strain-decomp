#include "types.h"
typedef struct {
    void* d;
    int pad04;
    int pad08;
    float t;
    int i10;
    float frac;
    float* a;
    float* b;
    unsigned char done;
} ClipCursor;
extern unsigned int func_00190E50(float);
extern float* func_00190E60(void*);
extern int func_00190EA0(void*);
extern int func_00190EB0(void*);
extern int func_00190F00(void*);
extern void* func_00190F10(ClipCursor*);
void func_00190C70(ClipCursor* c) {
    float len;
    unsigned int frames;
    int stride;
    unsigned int idx;
    int i0;
    float* base;
    int i1;
    c->t = 0.0f;
    c->done = 0;
    len = func_00190F00(func_00190F10(c));
    if (func_00190EB0(func_00190F10(c))) {
        while (c->t >= len) {
            c->t -= len;
        }
    } else if (c->t >= len) {
        c->t = len;
        c->done = 1;
    }
    frames = func_00190F00(func_00190F10(c));
    stride = func_00190EA0(func_00190F10(c));
    c->i10 = 0;
    base = func_00190E60(func_00190F10(c));
    idx = func_00190E50(c->t);
    i0 = idx * func_00190EA0(func_00190F10(c));
    if (func_00190EB0(func_00190F10(c))) {
        i1 = (idx < frames - 1) ? i0 + stride : 0;
    } else {
        i1 = (idx < frames) ? i0 + stride : i0;
    }
    c->frac = c->t - idx;
    c->a = base + i0;
    c->b = base + i1;
}
