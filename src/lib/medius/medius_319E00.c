/*
 * lib/medius: 5 files, 00319E00-0031A1E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00319E00 */
extern float D_004E1BCC;
extern float Libc_Cosf(float x);
void WindowKernel(float *buf, int n, float a, float b)
{
    int half = n >> 1;
    float *lo = buf;
    float *hi = buf + n - 1;
    float p2 = b;
    float k, p1, t, w;
    int i;
    k = Libc_Cosf(D_004E1BCC / (float)(n - 1));
    p1 = k * b;
    k = k + k;
    w = a - b;
    *lo++ *= w;
    *hi-- *= w;
    w = a - p1;
    *lo++ *= w;
    *hi-- *= w;
    for (i = 2; i + 2 < half; i += 3) {
        t = k * p1; t -= p2;
        w = a - t;
        *lo++ *= w;
        *hi-- *= w;
        p2 = k * t; p2 -= p1;
        w = a - p2;
        *lo++ *= w;
        *hi-- *= w;
        p1 = k * p2; p1 -= t;
        w = a - p1;
        *lo++ *= w;
        *hi-- *= w;
    }
    if (i < half) {
        t = k * p1; t -= p2;
        w = a - t;
        *lo++ *= w;
        *hi-- *= w;
        i++;
        if (i < half) {
            p2 = k * t; p2 -= p1;
            w = a - p2;
            *lo++ *= w;
            *hi-- *= w;
        }
    }
    if (n & 1)
        *lo *= a + b;
}
/* merge_units: end func_00319E00 */

/* merge_units: begin func_0031A018 */
typedef struct { int n; int x4; void *buf; } ObjA018;
extern void *(*D_004E1D34)(int n, int size);
int InitSpCBM(int n, ObjA018 **out)
{
    ObjA018 *o = D_004E1D34(1, 0xC);
    if (o == 0) return 1;
    *out = o;
    o->n = n;
    o->x4 = 0;
    o->buf = D_004E1D34(n, 4);
    return 0;
}
/* merge_units: end func_0031A018 */

/* merge_units: begin func_0031A090 */
typedef struct { char pad[8]; void *buf; } ObjA090;
extern void (*D_004E1D38)(void *p);
void FreeSpCBM(ObjA090 **pp)
{
    if (*pp == 0) return;
    if ((*pp)->buf) {
        D_004E1D38((*pp)->buf);
        (*pp)->buf = 0;
    }
    if (*pp) {
        D_004E1D38(*pp);
        *pp = 0;
    }
}
/* merge_units: end func_0031A090 */

/* merge_units: begin func_0031A0F0 */
typedef struct { int pos; int size; float *buf; } RingA0F0;
extern int (*D_004E1D40)(void *d, const void *s, int n);
extern int CalcCircBufPosition(int a, int size, int pos);
void PutFrameSpCBM(RingA0F0 *r, int off, int n, float *in)
{
    int pos = r->pos;
    int size = r->size;
    float *buf = r->buf;
    int i = CalcCircBufPosition(off, size, pos);
    int rem = pos - i;
    if (rem >= n) {
        D_004E1D40(buf + i, in, n * 4);
    } else {
        D_004E1D40(buf + i, in, rem * 4);
        D_004E1D40(buf, in + rem, (n - rem) * 4);
    }
    r->size = CalcCircBufPosition(n, size, pos);
}
/* merge_units: end func_0031A0F0 */

/* merge_units: begin func_0031A1E0 */
typedef struct { int pos; int size; float *buf; } RingA1E0;
void GetFrameSpCBM(RingA1E0 *r, int off, int n, float *out)
{
    int pos = r->pos;
    int size = r->size;
    float *buf = r->buf;
    int i = CalcCircBufPosition(-(off + ((n + 1) >> 1)), size, pos);
    int rem = pos - i;
    if (rem >= n) {
        D_004E1D40(out, buf + i, n * 4);
    } else {
        D_004E1D40(out, buf + i, rem * 4);
        D_004E1D40(out + rem, buf, (n - rem) * 4);
    }
}
/* merge_units: end func_0031A1E0 */
