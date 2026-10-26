typedef struct { int off; int a; int b; int kind; unsigned int x10; int x14; int x18; unsigned char c1C; char pad[3]; } E2E2F30;
typedef struct { int a; int cnt; char name[0x20]; E2E2F30 *objs[64]; int vals[64]; } S2E2F30;
typedef struct { unsigned char b0; unsigned char b1; unsigned char b2; unsigned char b3; int x4; int x8;
                 char name[16]; char *x1C; char *x20; int x24; int x28; int x2C; int x30; int x34; int *x38; unsigned int *x3C; char pad40[4]; } Q2E2F30;
extern S2E2F30 D_0058DF98[];
extern unsigned int D_0058806C;
extern void *memcpy(void *, const void *, unsigned int);
extern int GlobalFieldErrorExceedsThreshold(Q2E2F30 *, int, int);

int CheckFieldsForUpdate(Q2E2F30 *q, int a1, unsigned char force, unsigned char *flags, unsigned char *out, unsigned int *len)
{
    unsigned char n = 0;
    S2E2F30 *s;
    E2E2F30 *e;
    unsigned char i;
    char *src;
    char *dst;

    if (!out) return 0;
    if (!len) return 0;
    if (!q) return 0;
    if (q->b0 >= 16) return 0;
    s = &D_0058DF98[q->b0];
    if (!s) return 0;
    for (i = 0; i < s->cnt; i++) {
        int *w;
        int sh;
        if (*len >= 511) continue;
        e = s->objs[i];
        if (!e) continue;
        if (i < 32) {
            w = &q->x28;
            sh = i;
        } else {
            w = &q->x24;
            sh = i >> 1;
        }
        if ((*w >> sh) & 1) {
            src = q->x1C + s->vals[i];
            dst = q->x20 + s->vals[i];
        } else {
            if (!e->x14) continue;
            if (!force) {
                if (q->x3C[i] + e->x10 >= D_0058806C) continue;
            }
            src = q->x1C + s->vals[i];
            dst = q->x20 + s->vals[i];
            if (!GlobalFieldErrorExceedsThreshold(q, a1, i)) continue;
        }
        if (510 - *len < e->a * e->b + 1) continue;
        *out++ = i;
        (*len)++;
        memcpy(out, src, e->a * e->b);
        {
            int sz = e->a * e->b;
            n++;
            *len += sz;
            out += sz;
        }
        *flags |= e->c1C;
        memcpy(dst, src, e->a * e->b);
        q->x3C[i] = D_0058806C;
    }
    return n;
}
