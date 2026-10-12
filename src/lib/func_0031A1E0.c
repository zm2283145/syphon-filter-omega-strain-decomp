typedef struct { int pos; int size; float *buf; } RingA1E0;
extern int (*D_004E1D40)(void *d, const void *s, int n);
extern int func_0031A2A8(int a, int size, int pos);
void func_0031A1E0(RingA1E0 *r, int off, int n, float *out)
{
    int pos = r->pos;
    int size = r->size;
    float *buf = r->buf;
    int i = func_0031A2A8(-(off + ((n + 1) >> 1)), size, pos);
    int rem = pos - i;
    if (rem >= n) {
        D_004E1D40(out, buf + i, n * 4);
    } else {
        D_004E1D40(out, buf + i, rem * 4);
        D_004E1D40(out + rem, buf, (n - rem) * 4);
    }
}
