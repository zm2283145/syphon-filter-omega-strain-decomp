extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);
int func_0034AB38(void *cd, unsigned int *buf, char *dst, int n, void *src)
{
    int r;
    buf[0] = n;
    r = func_0034A828(cd, buf, 1, src, 16);
    if (r < 0) return r;
    if (func_0034A7A8(cd, 7, buf, 0x14, n + 0x14) < 0) return -0x21E;
    r = func_0034A968(cd, dst, buf, 5);
    if (r < 0) return r;
    return buf[0];
}