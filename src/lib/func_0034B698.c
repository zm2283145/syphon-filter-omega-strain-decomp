extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);
int func_0034B698(void *cd, unsigned int *buf, unsigned int a, unsigned int *p)
{
    buf[0] = a;
    if (p) buf[1] = *p; else buf[1] = 0;
    if (func_0034A7A8(cd, 0x35, buf, 8, 8) < 0) return -0x21E;
    if (p) *p = buf[1];
    return buf[0];
}