extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034B9E8(void *cd, int *buf, int *out);
extern int func_0034B9D0(void *cd, int *buf, int *dst, int n);
extern int func_0034B9B8(void *cd, int *buf, int *dst, int n);
extern int func_0034BAC8(void *cd, int *buf, int id, int x);
int func_0034BBE8(void *cd, int *buf, int *id, int n)
{
    int r;
    if (id == 0) return -0x21C;
    if (func_0034B9E8(cd, buf, id) < 0) {
        r = func_0034B9B8(cd, buf, id, n);
        if (r < 0) return r;
    }
    return 0;
}