/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern void func_00397840(SkaWords6* out, int a1, int a2);

/* Push a time value if the four-slot stack is not full. */
void AnimContext_PushTime(SkaTimeStack* s, float t) {
    if ((unsigned int)s->count < 4) {
        s->times[s->count] = t;
        s->count = s->count + 1;
    }
}

/* Fill a six-word value from func_00397840 with a zero third argument. */
void func_003AE050(SkaWords6* self, int a1) {
    SkaWords6 tmp;
    int w;

    func_00397840(&tmp, a1, 0);
    w = tmp.w[0];
    self->w[0] = w;
    w = tmp.w[1];
    self->w[1] = w;
    w = tmp.w[2];
    self->w[2] = w;
    w = tmp.w[3];
    self->w[3] = w;
    w = tmp.w[4];
    self->w[4] = w;
    w = tmp.w[5];
    self->w[5] = w;
}

/* Six-word copy assignment. */
SkaWords6* func_003AE0B0(SkaWords6* dst, SkaWords6* src) {
    dst->w[0] = src->w[0];
    dst->w[1] = src->w[1];
    dst->w[2] = src->w[2];
    dst->w[3] = src->w[3];
    dst->w[4] = src->w[4];
    dst->w[5] = src->w[5];
    return dst;
}

/* Fill a six-word value from func_00397840, passing src and its word +0x14. */
void func_003AE0F0(SkaWords6* self, SkaWords6* src) {
    SkaWords6 tmp;
    int w;

    func_00397840(&tmp, (int)src, src->w[5]);
    w = tmp.w[0];
    self->w[0] = w;
    w = tmp.w[1];
    self->w[1] = w;
    w = tmp.w[2];
    self->w[2] = w;
    w = tmp.w[3];
    self->w[3] = w;
    w = tmp.w[4];
    self->w[4] = w;
    w = tmp.w[5];
    self->w[5] = w;
}
