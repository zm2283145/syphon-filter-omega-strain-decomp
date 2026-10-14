/*
 * lib/medius: 4 files, 0031EBC8-0031EDC8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0031EBC8 */
#include "types.h"
typedef struct {
    int pad0[2];
    float scale;
    int padC;
    short count;
    short pad12;
    signed char mode;
    signed char state;
} g2Det;
char func_0031EBC8(short level, unsigned short dur, g2Det* d, float val) {
    int th = level < 255 ? level : 255;
    if (d->mode == 1) {
        d->count = 0;
        if (d->state == 0 && val >= (float)th) {
            d->state = 1;
        }
    } else {
        short lim = (unsigned int)(dur * d->scale + 0.5f);
        d->count++;
        if (lim < d->count) {
            d->state = 0;
            if (d->count > 0x7FBC) {
                d->count = 0x7FBC;
            }
        }
    }
    return d->state;
}
/* merge_units: end func_0031EBC8 */

/* merge_units: begin func_0031ECC0 */
extern volatile float D_004E1C5C;
typedef struct { char pad[0x14]; signed char a; signed char b; } S_0031ECC0;
int func_0031ECC0(S_0031ECC0* p, short n, float x) { int r = 0; if (p->a == 1 && n == p->a && p->b == n && D_004E1C5C <= x) r = 1; return r; }
/* merge_units: end func_0031ECC0 */

/* merge_units: begin func_0031ED08 */
typedef struct {
    float a;
    float b;
    float c;
    short pad;
    short e;
    short f;
    signed char g;
    unsigned char h;
    unsigned char i;
    unsigned char j;
} S;

extern const float D_004E1C34;
extern void *(*D_004E1D34)(int n, int size);

int func_0031ED08(S **pp, short n, float f)
{
    S *s;
    if (pp == 0) return 1;
    *pp = 0;
    s = D_004E1D34(1, 0x18);
    if (s == 0) return 1;
    *pp = s;
    s->a = 5059644.0f;
    s->b = 15636450.0f;
    s->e = 0; s->f = 0; s->g = -2; s->h = 0; s->i = 0; s->j = 0;
    s->c = f * D_004E1C34 / n;
    return 0;
}
/* merge_units: end func_0031ED08 */

/* merge_units: begin func_0031EDC8 */
#include "hook_free_ptr.h"

/* compiler: ee-gcc 2.96 -O2 */
/* Free a pointer through the hook and clear it. */
DEFINE_HOOK_FREE_PTR_RET0(func_0031EDC8)
/* merge_units: end func_0031EDC8 */
