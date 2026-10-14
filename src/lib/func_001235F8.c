typedef struct { unsigned char *_p; int _r; } FILE;
extern int __srefill(FILE *);
extern void *func_00125DC0(const void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
char *func_001235F8(char *buf, int n, FILE *fp)
{
    unsigned int len;
    char *s;
    unsigned char *p, *t;

    if (n < 2)
        return 0;

    s = buf;
    n--;
    do {
        if ((len = fp->_r) <= 0) {
            if (__srefill(fp)) {
                if (s == buf)
                    return 0;
                break;
            }
            len = fp->_r;
        }
        p = fp->_p;
        if (len > n)
            len = n;
        t = (unsigned char *)func_00125DC0((void *)p, '\n', len);
        if (t != 0) {
            len = ++t - p;
            fp->_r -= len;
            fp->_p = t;
            (void)memcpy((void *)s, (void *)p, len);
            s[len] = 0;
            return buf;
        }
        fp->_r -= len;
        fp->_p += len;
        (void)memcpy((void *)s, (void *)p, len);
        s += len;
    } while ((n -= len) != 0);
    *s = 0;
    return buf;
}