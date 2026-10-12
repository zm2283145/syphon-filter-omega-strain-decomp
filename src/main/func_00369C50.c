#include "types.h"
typedef struct {
    unsigned char hi;
    unsigned char lo;
    unsigned char rx;
    unsigned char ry;
    unsigned char lx;
    unsigned char ly;
    unsigned char pr[12];
    char pad[0x2C - 0x12];
} PadRaw369C50;
typedef struct {
    char pad0[0x100];
    int port;
    unsigned int held;
    int pressed;
    int cur;
    int x110;
    int x114;
    int prev;
    char pad11C[0x10];
    float stick[4];
    float delta[4];
    int pr[12];
    int prDelta[12];
    int state;
    unsigned char connected;
} Pad369C50;
int func_0026B3F8(int, PadRaw369C50*);
void func_0026B4D0(int, unsigned char*);
int func_0026B5A0(int);
extern int D_004BBE20[];

static inline float PadAxis_369C50(unsigned int v)
{
    return (float)v - 127.5f;
}

void func_00369C50(Pad369C50* p)
{
    PadRaw369C50 b;
    if (!p->connected) {
        unsigned char st[4];
        func_0026B4D0(p->port, st);
        if (st[2] != 0xFF) {
            p->state = 0;
            return;
        }
        p->connected = 1;
    }
    p->state = func_0026B5A0(p->port);
    if (p->state == 0) {
        p->connected = 0;
        return;
    }
    if (p->state == 1) {
        if (func_0026B3F8(p->port, &b) == 0x12) {
            int bits;
            float lx, ly, rx, ry;
            int i;
            p->prev = p->cur;
            bits = (b.hi << 8) | b.lo;
            p->held |= bits;
            bits ^= 0xFFFF;
            bits &= p->held;
            p->pressed = bits & ~p->cur;
            p->cur = bits;
            p->x110 |= p->cur;
            p->x114 ^= p->pressed;
            lx = PadAxis_369C50(b.lx);
            ly = PadAxis_369C50(b.ly);
            rx = PadAxis_369C50(b.rx);
            ry = PadAxis_369C50(b.ry);
            p->delta[0] = lx - p->stick[0];
            p->delta[1] = ly - p->stick[1];
            p->delta[2] = rx - p->stick[2];
            p->delta[3] = ry - p->stick[3];
            p->stick[0] = lx;
            p->stick[1] = ly;
            p->stick[2] = rx;
            p->stick[3] = ry;
            for (i = 0; i < 12; i++) {
                int v = b.pr[i];
                if (!(p->held & D_004BBE20[i]))
                    v = 0;
                p->prDelta[i] = v - p->pr[i];
                p->pr[i] = v;
            }
        }
    }
}