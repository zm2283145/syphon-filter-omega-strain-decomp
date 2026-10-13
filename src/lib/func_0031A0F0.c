typedef struct { int pos; int size; float *buf; } RingA0F0;
extern int (*D_004E1D40)(void *d, const void *s, int n);
extern int func_0031A2A8(int a, int size, int pos);
void func_0031A0F0(RingA0F0 *r, int off, int n, float *in)
{
    int pos = r->pos;
    int size = r->size;
    float *buf = r->buf;
    int i = func_0031A2A8(off, size, pos);
    int rem = pos - i;
    if (rem >= n) {
        D_004E1D40(buf + i, in, n * 4);
    } else {
        D_004E1D40(buf + i, in, rem * 4);
        D_004E1D40(buf, in + rem, (n - rem) * 4);
    }
    r->size = func_0031A2A8(n, size, pos);
}
