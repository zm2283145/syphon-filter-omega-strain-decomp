extern int func_0034A7A8(void *cd, int fno, void *buf, int ssize, int rsize);
extern int func_0034A828(void *cd, void *buf, int idx, void *src, int len);
extern int func_0034A880(void *cd, void *dst, void *buf, int idx, int len);
extern int func_0034A968(void *cd, char *dst, void *buf, int idx);

int func_0034ABE0(void *cd, unsigned int *buf, unsigned int flags, char *dst, int len, void *addr, unsigned int c, unsigned int d, ...)
{
    int r;
    buf[2] = c; buf[3] = d; buf[8] = 0; buf[0] = flags; buf[1] = len;
    if (flags & 0x80) {
        __builtin_va_list ap;
        __builtin_stdarg_start(ap, d);
        buf[8] = __builtin_va_arg(ap, unsigned int);
        __builtin_va_end(ap);
    }
    r = func_0034A828(cd, buf, 4, addr, 16);
    if (r < 0) return r;
    if (func_0034A7A8(cd, 0x12, buf, 0x24, len + 0x20) < 0) return -0x21E;
    r = func_0034A968(cd, dst, buf, 8);
    if (r < 0) return r;
    return buf[0];
}