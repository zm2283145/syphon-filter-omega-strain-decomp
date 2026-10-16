#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct Ev_415510 {
    short type;
    short pad;
    short a;
    short b;
    short button;
    short p0A;
    int p0C;
    short p10;
    short count;
};
struct Node_415510 { char pad[8]; int value; };
struct Pad_415510 { char pad[0x14C]; unsigned int cur; char pad150[8]; unsigned int prev; char pad15C[0x1C0 - 0x15C]; };
struct W_415510 {
    VPAD16(p) VPAD8(q) VPAD1(r)
    virtual void Event(Ev_415510* ev);
    char pad[0x24];
    int count;
    Node_415510* first;
    char pad30[0x38];
    unsigned int mask;
};
static unsigned int D_004940B0[16] = {
    0x1000, 0x4000, 0x8000, 0x2000, 0x10, 0x40, 0x80, 0x20,
    0x200, 0x400, 0x4, 0x1, 0x8, 0x2, 0x800, 0x100
};
extern int D_00533870;
extern long D_00533878;
extern int D_00571FD8;
extern int D_00571FE0[2][16];
extern int D_00572060[2][16];

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

extern "C" void func_00415510(W_415510* w, Pad_415510* pads)
{
    int now;
    int p;
    now = DivTime(D_00533878 + (int)((float)(unsigned int)(*(volatile int*)0x10000800 + D_00533870) / 5.76f));
    for (p = 0; p < 2; p++) {
        int j;
        for (j = 0; j < 16; j++) {
            unsigned int m = D_004940B0[j];
            unsigned int cur = pads[p].cur;
            if ((m & cur) != (m & pads[p].prev)) {
                Ev_415510 ev;
                ev.type = 1;
                ev.pad = p;
                ev.a = 0;
                unsigned int bm = D_004940B0[j];
                bool rel = !(bm & cur);
                ev.b = rel;
                ev.button = D_004940B0[j];
                ev.count = 0;
                D_00571FD8 = w->count ? w->first->value : 0;
                D_00571FE0[p][j] = 0;
                D_00572060[p][j] = now;
                w->Event(&ev);
            } else if ((m & cur) && (w->mask & m) && w->count && D_00571FD8 == w->first->value) {
                int e = now - D_00572060[p][j] - 300;
                if (e >= 0) {
                    int c = D_00571FE0[p][j];
                    int n = c >= 4 ? (e - 600) / 75 + 5 : e / 150 + 1;
                    if (c < n) {
                        Ev_415510 ev;
                        ev.type = 1;
                        ev.pad = p;
                        ev.a = 0;
                        ev.b = 0;
                        ev.button = D_004940B0[j];
                        ev.count = D_00571FE0[p][j]++;
                        w->Event(&ev);
                    }
                }
            }
        }
    }
}







