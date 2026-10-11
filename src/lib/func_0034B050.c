extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);

int func_0034B050(void *cd, int *buf, int a, void *src, int len, int *p, void *addr, int x, int y)
{
    int r;
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    buf[2] = len; buf[3] = y; buf[4] = x;
    r = func_0034A828(cd, buf, 5, addr, 16);
    if (r < 0) return r;
    r = func_0034A828(cd, buf, 9, src, len);
    if (r < 0) return r;
    if (func_0034A7A8(cd, 0xE, buf, len + 0x24, 8) < 0) return -0x21E;
    if (p) *p = buf[1];
    return buf[0];
}