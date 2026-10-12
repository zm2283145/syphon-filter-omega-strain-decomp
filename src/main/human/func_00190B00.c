#include "types.h"
typedef struct {
    unsigned int type;
    unsigned int frames;
    int stride;
    int pad0C;
    int loop;
} ClipData;
typedef struct {
    ClipData* d;
    int pad04;
    int pad08;
    float t;
    int i10;
    float frac;
    float* a;
    float* b;
    unsigned char done;
} ClipCursor;
void Clip_AdvanceCursor(ClipCursor* c, float t) {
    float len;
    unsigned int frames;
    int stride;
    ClipData* d;
    unsigned int type;
    unsigned int idx;
    int i0;
    float* base;
    int i1;
    c->t = t;
    c->done = 0;
    len = (int)c->d->frames;
    if (c->d->loop) {
        while (c->t >= len) {
            c->t -= len;
        }
    } else if (c->t >= len) {
        c->t = len;
        c->done = 1;
    }
    frames = c->d->frames;
    stride = c->d->stride;
    c->i10 = 0;
    d = c->d;
    type = d->type;
    if (type >= 3) {
        base = (float*)((char*)d + 0x70);
    } else if (type == 2) {
        base = (float*)((char*)d + 0x40);
    } else {
        base = (float*)((char*)d + 0x30);
    }
    idx = (int)c->t;
    i0 = idx * d->stride;
    if (d->loop) {
        i1 = (idx < frames - 1) ? i0 + stride : 0;
    } else {
        i1 = (idx < frames) ? i0 + stride : i0;
    }
    c->frac = c->t - idx;
    c->a = base + i0;
    c->b = base + i1;
}



