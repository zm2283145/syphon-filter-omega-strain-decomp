extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);

int func_0034A9A8(void *cd, unsigned int *buf, void *dst, int n, int x)
{
    int r;
    buf[0] = n; buf[1] = x;
    r = func_0034A828(cd, buf, 2, dst, n * 8);
    if (r < 0) return r;
    if (func_0034A7A8(cd, 0x14, buf, n * 8 + 8, n * 8 + 4) < 0) return -0x21E;
    r = func_0034A880(cd, dst, buf, 2, n * 8);
    if (r < 0) return r;
    return buf[0];
}