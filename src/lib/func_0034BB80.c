extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034B9E8(void *cd, int *buf, int *out);
extern int func_0034B9D0(void *cd, int *buf, int *dst, int n);
extern int func_0034B9B8(void *cd, int *buf, int *dst, int n);
extern int func_0034BAC8(void *cd, int *buf, int id, int x);
int func_0034BB80(void *cd, int *buf, int *id, int n, int x)
{
    int r;
    r = func_0034B9D0(cd, buf, id, n);
    if (r < 0) return r;
    r = func_0034BAC8(cd, buf, *id, x);
    if (r < 0) return r;
    return 0;
}