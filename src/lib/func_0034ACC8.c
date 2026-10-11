extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);

int func_0034ACC8(void *cd, unsigned int *buf, void *src)
{
    int r;
    r = func_0034A828(cd, buf, 1, src, 0x40);
    if (r < 0) return r;
    if (func_0034A7A8(cd, 1, buf, 0x44, 4) < 0) return -0x21E;
    return buf[0] ? buf[0] : -0x21C;
}