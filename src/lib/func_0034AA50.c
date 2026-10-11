extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);

int func_0034AA50(void *cd, unsigned int *buf, unsigned int flags, void *dst, char *str, unsigned int b, unsigned int c, ...)
{
    int n;
    buf[0] = flags; buf[1] = b; buf[2] = c; buf[3] = 0;
    if (flags & 0x80) {
        __builtin_va_list ap;
        __builtin_stdarg_start(ap, c);
        buf[3] = __builtin_va_arg(ap, unsigned int);
        __builtin_va_end(ap);
    }
    n = func_0034A8D8(cd, buf, 5, str);
    if (n < 0) return n;
    buf[4] = n;
    if (func_0034A7A8(cd, 6, buf, n + 0x14, 0x14) < 0) return -0x21E;
    n = func_0034A880(cd, dst, buf, 1, 16);
    if (n < 0) return n;
    return buf[0];
}