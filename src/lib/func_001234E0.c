struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
    unsigned char *_p; int _r; int _w; short _flags; short _file;
    struct __sbuf _bf; int _lbfsize; void *_cookie;
    int (*_read)(void *, char *, int); int (*_write)(void *, const char *, int);
    int (*_seek)(void *, int, int); int (*_close)(void *);
    struct __sbuf _ub; unsigned char *_up; int _ur;
    unsigned char _ubuf[3]; unsigned char _nbuf[1];
    struct __sbuf _lb; int _blksize; int _offset; struct _reent *_data;
} FILE;
struct _glue { struct _glue *_next; int _niobs; FILE *_iobs; };
struct _reent { int _errno; char p0[0x34]; int __sdidinit; char p1[0x1D8 - 0x3C]; struct _glue __sglue; };extern struct _reent *D_00489738;
extern void __sinit(struct _reent *);
extern int func_00124BC0(struct _reent *, int (*)(FILE *));
int fflush(FILE *fp)
{
    int n, t;
    unsigned char *p;
    if (fp == 0) return func_00124BC0(D_00489738, fflush);
    do {
        if ((fp)->_data == 0)
            (fp)->_data = D_00489738;
        if (!(fp)->_data->__sdidinit)
            __sinit((fp)->_data);
    } while (0);
    t = fp->_flags;
    if ((t & 8) == 0 || (p = fp->_bf._base) == 0) return 0;
    n = fp->_p - p;
    fp->_p = p;
    fp->_w = t & (1 | 2) ? 0 : fp->_bf._size;
    while (n > 0) {
        t = (*fp->_write)(fp->_cookie, (char *)p, n);
        if (t <= 0) {
            fp->_flags |= 0x40;
            return -1;
        }
        p += t;
        n -= t;
    }
    return 0;
}
