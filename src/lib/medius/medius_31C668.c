/*
 * lib/medius: 8 files, 0031C668-0031CC50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031C668 */
#include "types.h"
typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; char f1C[0x14]; void* p30; void* p34; } Handle_0031C668;
extern unsigned short D_004E1D4C;
extern void (*D_004E1D38)(void*);
extern void func_00317AC0(void* p);
int func_0031C668(Handle_0031C668** pp)
{
    Handle_0031C668* h;
    if (!pp) return 0x181A;
    if (!*pp || (*pp)->magic != 0xFACE) return 0x17D4;
    if ((*pp)->state != 10) return 0x17E3;
    D_004E1D4C--;
    h = *pp;
    h->magic = 0;
    func_00317AC0(h->f1C);
    if (h->p30) { D_004E1D38(h->p30); h->p30 = 0; }
    if (h->p34) { D_004E1D38(h->p34); h->p34 = 0; }
    D_004E1D38(h);
    *pp = 0;
    return 0;
}
/* merge_units: end func_0031C668 */

/* merge_units: begin func_0031C728 */
typedef struct BitW316DF0 {
    unsigned char* buf;
    unsigned short size;
    char pad6[0x10 - 6];
    unsigned short* pos;
    unsigned char* bit;
} BitW316DF0;
extern short D_004B5440[];
extern void func_00316DF0(BitW316DF0* w, short val, int n);
void func_0031C728(unsigned int* p, unsigned char* buf, unsigned short* pos, unsigned char* bit, unsigned short size, unsigned short v)
{
    BitW316DF0 w;
    short* t;
    int i; unsigned int* q;
    w.size = size;
    w.pos = pos;
    w.bit = bit;
    w.buf = buf;
    p[16] = v;
    p[15] = 0;
    t = D_004B5440; q = p;
    for (i = 16; i >= 0; i--) {
        func_00316DF0(&w, (unsigned char)*q++, *t++);
    }
}
/* merge_units: end func_0031C728 */

/* merge_units: begin func_0031C7A8 */
typedef struct { float prev; float y; float coef; } g2DcState;
extern float D_004E1C78;
extern float D_004E1C7C;
void func_0031C7A8(short* in, float* out, int n, g2DcState* st) {
    float y = st->y;
    float coef = st->coef;
    float prev = st->prev;
    float x;
    if (y > 0.0f ? y < D_004E1C78 : y > D_004E1C7C) y = 0.0f;
    while (n-- > 0) {
        x = *in++;
        y = x - prev + coef * y;
        prev = x;
        *out++ = y;
    }
    st->prev = prev;
    st->y = y;
}
/* merge_units: end func_0031C7A8 */

/* merge_units: begin func_0031C838 */
typedef struct { int a; int b; float c; } T_0031C838;
extern T_0031C838* (*D_004E1D34)(int n, int size);
int func_0031C838(T_0031C838** pp, float x) { T_0031C838* p = D_004E1D34(1, sizeof(T_0031C838)); *pp = p; if (!p) return 1; p->c = x; p->b = 0; p->a = 0; return 0; }
/* merge_units: end func_0031C838 */

/* merge_units: begin func_0031C898 */
#include "hook_free_ptr.h"

/* compiler: ee-gcc 2.96 -O2 */
/* Free a pointer through the hook and clear it. */
DEFINE_HOOK_FREE_PTR(func_0031C898)
/* merge_units: end func_0031C898 */

/* merge_units: begin func_0031C8D8 */
/* asm("" : "+r"(c) : "r"(spec)) emits no code; the extra use of the spec base
 * address tips global-alloc priority so it gets $s4 (retail) instead of $s5. */
extern float D_004B3968[];
extern float D_004E1C80;
extern float func_00317780(float* a, float* b, int n);
extern float func_00316ED8(float* h, int m, float f, float* a, int n, float g);
extern int func_0031CB78(float f, float* spec, float* out, float thr);
extern int func_0031CC50(float* spec, int* idx, int* sel);
extern void func_0031CDC0(float* spec, int* idx, int* cnt, int* sel);
extern void func_0031CF58(float* spec, int pk, int* idx, int* cnt, int* sel);
extern float func_0031D088(int k, float* h, int m, float* a, int n, float g, float* best);

int func_0031C8D8(float* a, int n, float* h, int m, float x, float y, float* d, float* e0, int* k)
{
    float* e = e0;
    int idx[8];
    float spec[74];
    float t;
    int sel;
    int cnt;
    float v;
    float scale;
    int i;
    int pk;
    int c;
    float tmp;
    int last;

    scale = func_00317780(a, a, n) + D_004E1C80;
    scale = 10.0f / scale;
    for (i = 0; i < 74; i += 2)
        spec[i] = func_00316ED8(h, m, D_004B3968[i], a, n, scale);
    for (i = 1; i < 74; i += 2)
        spec[i] = spec[i - 1];
    pk = func_0031CB78(x, spec, &t, y);
    tmp = t;
    t = spec[pk];
    spec[pk] = tmp;
    cnt = func_0031CC50(spec, idx, &sel);
    func_0031CDC0(spec, idx, &cnt, &sel);
    func_0031CF58(spec, pk, idx, &cnt, &sel);
    tmp = t;
    t = spec[pk];
    spec[pk] = tmp;
    c = 0;
    last = cnt - 1;
    for (i = 0; i < cnt; i++) {
        if (i == 0 || i == last || i == sel) {
            int j;
            if (i == sel)
                *k = c;
            j = idx[i];
            v = spec[j];
            d[c] = func_0031D088(j, h, m, a, n, scale, &v);
            if (j == pk) {
                float f = v;
                if (f < y)
                    f = (y + f) * 0.5f;
                v = f;
            }
            e[c] = v;
            c++;
        }
    }
    __asm__("" : "+r"(c) : "r"(spec)); /* ref barrier, emits no code */
    return c;
}
/* merge_units: end func_0031C8D8 */

/* merge_units: begin func_0031CB78 */
extern float D_004E1C88; /* 1.333f in .lit4 */

int func_0031CB78(float f, float *spec, float *out, float thr)
{
    float hi = f * D_004E1C88;
    float lo = f * 0.75f;
    int i = 0;
    int best;
    float m;
    while (D_004B3968[i] < lo) i++;
    m = spec[i];
    best = i;
    do {
        if (m < spec[i]) {
            m = spec[i];
            best = i;
        }
        i++;
    } while (i < 74 && D_004B3968[i] <= hi);
    if (m < thr)
        *out = (thr + m) * 0.5f;
    else
        *out = m;
    return best;
}
/* merge_units: end func_0031CB78 */

/* merge_units: begin func_0031CC50 */
extern float D_004E1C8C;
extern float D_004E1C90;
extern float D_004E1C94;
extern void func_0031BB28(float *x, int start, int *pos, float *val);

int func_0031CC50(float *x, int *out, int *best)
{
    int pos;
    float val;
    float prev = -1.0f;
    int n = 0;
    int b = 0;
    int lag = 0x49;
    float thr;

    while (n < 5) {
        func_0031BB28(x, lag + 1, &pos, &val);
        if (val < prev * D_004E1C8C)
            break;
        {
            float t = prev * D_004E1C90;
            *out = pos;
            if (t <= val)
                b = n;
        }
        lag = pos;
        out++;
        n++;
        prev = val;
        thr = D_004B3968[lag] * D_004E1C94;
        if (thr < D_004B3968[0])
            break;
        while (thr < D_004B3968[lag])
            lag--;
        while (lag >= 0 && x[lag] < x[lag + 1])
            lag--;
        if (lag < 0)
            break;
    }
    *best = b;
    return n;
}
/* merge_units: end func_0031CC50 */
