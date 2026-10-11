extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);

int func_0034ADD0(void *cd, int *buf, int a, void *dst, int len, int *p, int x)
{
    int r;
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    buf[2] = len; buf[3] = x;
    if (func_0034A7A8(cd, 4, buf, 16, len + 8) < 0) return -0x21E;
    if (buf[0] < 0) return buf[0];
    if (p) *p = buf[1];
    r = func_0034A880(cd, dst, buf, 2, buf[0]);
    if (r < 0) return r;
    return buf[0];
}