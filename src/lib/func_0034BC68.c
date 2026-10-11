extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034B9E8(void *cd, int *buf, int *out);
extern int func_0034B9D0(void *cd, int *buf, int *dst, int n);
extern int func_0034B9B8(void *cd, int *buf, int *dst, int n);
extern int func_0034BAC8(void *cd, int *buf, int id, int x);
int func_0034BC68(void *cd, int *buf, int *p, int *q)
{
    if (func_0034A7A8(cd, 0x23, buf, 0, 0xC) < 0) return -0x21E;
    if (p) *p = buf[1];
    if (q) *q = buf[2];
    return buf[0];
}