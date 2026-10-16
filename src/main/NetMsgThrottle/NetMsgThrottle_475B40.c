#include "types.h"
typedef struct H1Chan { float unk0; float prev; float last; float pad0C; float cur; char pad14[0x3C - 0x14]; } H1Chan;
typedef struct H1Anim { char pad00[0x80]; H1Chan* chans; } H1Anim;
static inline float h1_fabs(float x) { float r; asm { abs.s r, x } return r; }
static inline unsigned char h1_far(float a, float b, float t) { return h1_fabs(a - b) > t; }
unsigned char Ladder_ChannelArrived(H1Anim* a, int ch, float thr) {
    H1Chan* c = &a->chans[ch];
    float cur = c->cur;
    unsigned char r = h1_fabs(cur - c->last) <= thr;
    if (r) r = h1_far(cur, c->prev, thr);
    return r;
}