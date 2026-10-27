#include "types.h"

typedef struct {
    short a;
    unsigned short ua;
    short b;
    unsigned short ub;
} LpdKey;

typedef struct {
    short count;
    short on;
    short a;
    short b;
    float fa;
    float fb;
} LpdTrack;

typedef struct {
    char pad0[0x2C18];
    LpdTrack trk[21];
    int** tbl;
    int time;
} Lpd;

extern int g_TimerAccum;
extern long g_TickCounter64;

static inline int DivTime(long n)
{
    int bit = 1 << 30;
    int q = 0;
    long d = 100;
    int i;
    d <<= 30;
    for (i = 0; i < 31; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}

void cMan_LipSyncPlay(Lpd* s, int* data)
{
    int* p;
    int i;
    s->tbl = (int**)data;
    p = (int*)s->tbl;
    if (p[0] < 0x7D00) {
        int* base;
        int off;
        int j;
        off = 0;
        base = p;
        for (j = 0; j <= 21; j++) {
            off += *p++;
            s->tbl[j] = base + off;
        }
    }
    for (i = 0; i < 21; i++) {
        s->trk[i].on = 1;
        s->trk[i].count = s->tbl[i + 1] - s->tbl[i];
        if (s->trk[i].count > 0) {
            LpdKey* k = (LpdKey*)s->tbl[i];
            s->trk[i].a = k->a;
            s->trk[i].b = k->b;
            s->trk[i].fa = 3.0517578125e-05f * k->ua;
            s->trk[i].fb = 3.0517578125e-05f * k->ub;
            if (s->trk[i].fa == 0.0f && s->trk[i].fb == 0.0f) {
                s->trk[i].a = s->trk[i].b;
            }
        } else {
            s->trk[i].a = 0;
            s->trk[i].b = 0;
            s->trk[i].fa = 0.0f;
            s->trk[i].fb = 0.0f;
        }
    }
    s->time = DivTime(g_TickCounter64 + (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f));
}