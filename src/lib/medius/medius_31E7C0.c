/*
 * lib/medius: 5 files, 0031E7C0-0031E988
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031E7C0 */
#include "types.h"
typedef struct { float* buf; int pad4; short count; } g2Scl;
extern float D_004E1C70;
void nemAgcUpdateCounter(g2Scl* s) {
    short i;
    float* p;
    if (s->count < 0x55) {
        float k = D_004E1C70;
        p = s->buf;
        for (i = 0; i < 0x21; i++) {
            *p++ *= k;
        }
    } else {
        s->count = 0x54;
    }
    s->count++;
}
/* merge_units: end func_0031E7C0 */

/* merge_units: begin func_0031E828 */
typedef struct { float* hist; float mean; short flag; } H_0031E828;
extern void* (*D_004E1D34)(int n, int size);
int nemAgcInit(H_0031E828** pp)
{
    H_0031E828* p;
    if (!pp) return 1;
    *pp = 0;
    p = D_004E1D34(1, sizeof(H_0031E828));
    if (!p) return 1;
    *pp = p;
    p->hist = D_004E1D34(33, sizeof(float));
    if (!p->hist) return 1;
    p->mean = 0;
    p->flag = 0;
    return 0;
}
/* merge_units: end func_0031E828 */

/* merge_units: begin func_0031E8B0 */
extern void (*D_004E1D38)(void*);
typedef struct { void* buf; } S_0031E8B0;
int nemAgcFree(S_0031E8B0** pp) { S_0031E8B0* p = *pp; if (!p) return 1; if (p->buf) { D_004E1D38(p->buf); p->buf = 0; p = *pp; } if (p) { D_004E1D38(p); *pp = 0; } return 0; }
/* merge_units: end func_0031E8B0 */

/* merge_units: begin func_0031E920 */
typedef struct {
    float x;
    float y;
    char pad8[0x13 - 8];
    unsigned char flag;
} S_0031E920;
void nemVadBlockDec(S_0031E920* s, float lim)
{
    float x = s->x;
    float y;
    if (x > 160000.0f) y = (x * -0x1.846f3ap-24f + 0x1.c49362p+1f) * x + 62071.0f; else y = (x * -0x1.7417b8p-18f + 0x1.030488p+2f) * x + 362.0f;
    s->y = y;
    s->flag = y < lim;
}
/* merge_units: end func_0031E920 */

/* merge_units: begin func_0031E988 */
typedef struct { char pad[0xE]; short cnt; char pad2[3]; char on; char flag; } G1S;
extern float D_004E1C1C;
void nemVadSpkrDec(short a, G1S* p, float lim, float v)
{
    if (p->on) {
        float x = (float)a - 42.5f;
        float t = v - D_004E1C1C;
        float m = (x <= t) ? t : x;
        if (m <= lim) {
            if (++p->cnt >= 2) {
                p->flag = 1;
                p->cnt = 1;
                return;
            }
            p->flag = 0;
            return;
        }
    }
    p->cnt = 0;
    p->flag = 0;
}
/* merge_units: end func_0031E988 */
